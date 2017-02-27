import sys
sys.path.append('../cy_python')
import cppy_load as cl



pom = cl.read_input()

for a in pom:
    print(pom[a])
