import sys
sys.path.append('../cy_python')
import cppy_load as cl
import func


pom = cl.read_input()
print(pom)
for video_id in range(pom['num_videos']):
    print("============================================")
    for cache_id in range(pom['num_caches']):
        vys = func.evaluate(pom['endpoints'],video_id,cache_id)
        print("Video: %d, Cache: %d = %d" % (video_id,cache_id,vys))

