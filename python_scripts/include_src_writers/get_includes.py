filename = 'include/all.txt'

source = open( filename, 'r' )
line = source.readline()

while line:
    print '#include "gto_d2_kit/'+line[:-1]+'"'
    line = source.readline()

source.close()
