cimport numpy
import numpy as np
cimport numpy as np
import cython
from libcpp.vector cimport vector
from libcpp.pair cimport pair
from libcpp.unordered_map cimport unordered_map
cdef extern from "../load.h":
    struct endpoint:
        np.int64_t l_data_c
        np.int64_t connections
        #vector[pair[np.int64_t,np.int64_t]] l_cache_s
        unordered_map[np.int64_t,np.int64_t] l_cache_s
        #vector[request] requests
        unordered_map[np.int64_t,np.int64_t] requests
    
    #struct cache:
    #    np.int64_t memory
    #    vector[np.int64_t] indexes

    struct google_input:
        np.int64_t num_videos
        np.int64_t num_endpoints
        np.int64_t num_requests
        np.int64_t num_caches

        #vector[cache] caches
        vector[endpoint] endpoints
        vector[np.int64_t] videos_size
    
    google_input read_input()


