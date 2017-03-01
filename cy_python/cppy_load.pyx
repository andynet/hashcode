from __future__ import print_function
cimport cpp_load
import pandas as pd
import numpy as np
cimport numpy as np
from queue import PriorityQueue
import itertools
from cython.parallel import prange ,parallel

def evaluate(endpoints,long video_id,long cache_id):
    """Calculate how many ms will safe video in cache_id
    nekontroluje ci sa zmesti do Cache
    :endpoints: Dictionary of Endpoints
    :video_id: id of video
    :cache_id: id of cache 
    :returns: miliseconds

    """
    ret = 0

    for endpoint in endpoints:
        #print(endpoint)
        if cache_id not in endpoint['l_cache_s']:
            continue
        #lepsia verzia lebo cez to netreba iterovat
        if video_id in endpoint['requests']:
            ret+=(endpoint['l_data_c']-endpoint['l_cache_s'].at[cache_id])*endpoint['requests'].at[video_id]

    return ret



def read_input():
    cdef pom =  cpp_load.read_input()
    for endpoint in pom['endpoints']:
        endpoint['requests'] = pd.Series(endpoint['requests'],dtype=np.int64)
        endpoint['l_cache_s'] = pd.Series(endpoint['l_cache_s'],dtype=np.int64)
    pom['videos_size'] = np.array(pom['videos_size'],dtype=np.int64)
    return pom

def video_caches_values(endpoints,long num_caches,long video_id, queue):
    ret = pd.Series()
    for cache_id in range(num_caches):
        value = evaluate(endpoints,video_id,cache_id)
        ret.at[cache_id] = value
    ret.sort_values(ascending=False)
    queue.put((ret,np.asarray(ret.index)),0)

class ByMaxPriorityQueue(PriorityQueue):

    tiebreaker = itertools.count()


    def put(self, val, index, *args, **kwargs):
        if index >= val[1].size:
            raise ValueError('BAd index')
        super().put((-val[0].iat[index], next(self.tiebreaker), (index, val)), *args, **kwargs)

    def get(self, *args, **kwargs):
        """
        return tuple (val,index)
        """
        key, tie, val = super().get(*args, **kwargs)
        return val

def get_priority_queue(google_input,queue):
    cdef long num_videos = google_input['num_videos']
    cdef long num_caches = google_input['num_caches']
    endpoints = google_input['endpoints']
    i = 0
    for video_id in range(num_videos):
        print("===================%02.02f===============" % (i/num_videos*100), end="\r")
        val = video_caches_values(endpoints,num_caches,video_id,queue)
        i+=1

    print("===================100.00===============")
