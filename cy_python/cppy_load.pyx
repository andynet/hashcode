cimport cpp_load

def read_input():
    cdef cpp_load.google_input pom = cpp_load.read_input()
    print(pom.num_videos)
    return ""
