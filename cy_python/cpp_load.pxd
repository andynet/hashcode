cimport numpy
import numpy as np
cimport numpy as np
import cython
from libcpp.vector cimport vector
from libcpp.pair cimport pair

cdef extern from "../load.h":
    struct request:
        int video_id
        int count

    struct endpoint:
        int l_data_c
        int connections
        vector[pair[int,int]] l_cache_s
        vector[request] requests
    
    struct cache:
        int memory
        vector[int] indexes

    struct google_input:
        int num_videos
        int num_endpoints
        int num_requests
        int num_caches

        vector[cache] caches
        vector[endpoint] endpoints
        vector[int] videos_size
    
    google_input read_input()


