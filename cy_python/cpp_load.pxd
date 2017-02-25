cimport numpy
import numpy as np

cdef extern from "../load.h":
    struct request:
        pass

    struct endpoint:
        pass
    
    struct cache:
        pass

    struct google_input:
        pass
    
    google_input read_input()
