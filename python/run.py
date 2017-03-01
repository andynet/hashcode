import sys
sys.path.append('../cy_python')
import cppy_load as cl

pom = cl.read_input()
#print(pom)
i = 0
queue = cl.ByMaxPriorityQueue()
cl.get_priority_queue(pom,queue)
fulls = 0
print("[*] Zaciname vypocet")
while (not queue.empty) and (fulls !=pom['num_cahces']):
    val, index = queue.get()
    
    
