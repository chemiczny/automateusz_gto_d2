shell = ['s', 'p', 'd' ]
shellsNo = [3, 3]
atoms = ['A', 'B', 'C']

matrixName = 'VNED2 vned2['+str(shellsNo[0])+']['+str(shellsNo[1])+'][3][3]'

def writeTabs(n, destiny):
    destiny.write(n*'\t')

def writeMatrix(destiny):
    destiny.write(matrixName+ '=\n')
    destiny.write('{\n')
    for shell1 in range(1, shellsNo[0]+1):
        writeTabs(1, destiny)
        destiny.write('{\n')
        for shell2 in range(1, shellsNo[1] + 1):
            writeTabs(2, destiny)
            destiny.write('{\n')
            writeSmallMatrix(shell1, shell2, 2, destiny)
            writeTabs(2, destiny)
            if shell2 == shellsNo[1]:
                destiny.write('}\n')
            else:
                destiny.write('},\n')
        writeTabs(1, destiny)
        if shell1 == shellsNo[0]:
            destiny.write('}\n')
        else:
            destiny.write('},\n')
    destiny.write('};\n')

def writeSmallMatrix(shell1, shell2, tabsNo, destiny):
    for atom1 in range(1, 4):
        writeTabs(tabsNo+1, destiny)
        destiny.write('{')
        for atom2 in range(1, 4):
            destiny.write('vne_second_derivative_'+str(shell1-1)+str(shell2-1)+'_'+str(atom1)+str(atom2)+" ")
            if atom2 != 3:
                destiny.write(", ")
        if atom1 == 3:
            destiny.write('}\n')
        else:
            destiny.write('},\n')


destiny = open('d2_vne_matrix.txt', 'w')
writeMatrix(destiny)
