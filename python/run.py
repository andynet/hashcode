import sys
sys.path.append('../cy_python')
import cppy_load as cl
import func
import timeit

pom = cl.read_input()
#print(pom)
i = 0
for video_id in range(pom['num_videos']):
    print("===================%02.02f=======================" %(i/pom['num_videos']*100))
    i+=1
    cl.video_caches_values(pom['endpoints'],pom['num_caches'],video_id)
        #t = timeit.timeit("func.evaluate(pom['endpoints'],video_id,cache_id)",number=10000,globals=globals())
        #print("Time for python=%f" % t)
        
        #t = timeit.timeit("cl.evaluate(pom['endpoints'],video_id,cache_id)",number=1000000,globals=globals())
        #print("Time for cython=%f" % t)


        #print("Video: %d, Cache: %d = %d" % (video_id,cache_id,vys))
