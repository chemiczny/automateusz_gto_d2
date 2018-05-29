shell = ['s', 'p', 'd']
shellsNo = [3, 3, 3, 3]
atoms = ['A', 'B', 'C', 'D']

matrixName = 'ERID2 erid2['+str(shellsNo[0])+']['+str(shellsNo[1])+']['+str(shellsNo[2])+']['+str(shellsNo[3])+'][4][4]'

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
            for shell3 in range(1, shellsNo[2]+1):
                writeTabs(3, destiny)
                destiny.write('{\n')
                for shell4 in range(1, shellsNo[3]+1):
                    writeTabs(4, destiny)
                    destiny.write('{\n')
                    writeSmallMatrix(shell1, shell2, shell3, shell4, 4, destiny)
                    writeTabs(4, destiny)
                    if shell4 == shellsNo[3]:
                        destiny.write('}\n')
                    else:
                        destiny.write('},\n')
                    
                writeTabs(3, destiny)
                if shell3 == shellsNo[2]:
                    destiny.write('}\n')
                else:
                    destiny.write('},\n')
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

def writeSmallMatrix(shell1, shell2, shell3, shell4, tabsNo, destiny):
    shellsStr = str(shell1-1)+str(shell2-1)+str(shell3-1)+str(shell4-1)
    for atom1 in range(1, 5):
        writeTabs(tabsNo+1, destiny)
        destiny.write('{')
        for atom2 in range(1, 5):
            destiny.write('second_derivative_ee_'+shellsStr+'_'+str(atom1)+str(atom2)+" ")
            if atom2 != 4:
                destiny.write(", ")
        if atom1 == 4:
            destiny.write('}\n')
        else:
            destiny.write('},\n')


destiny = open('d2_ee_matrix.txt', 'w')
writeMatrix(destiny)
