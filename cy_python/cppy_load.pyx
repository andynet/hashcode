cimport cpp_load
import pandas as pd
import numpy as np
cimport numpy as np
def evaluate(endpoints,video_id,cache_id):
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
        """
        for request in endpoint['requests']:
            if request['video_id']==video_id:
                ret+=(endpoint['l_data_c']-endpoint['l_cache_s'][cache_id])*request['count']
        """
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






