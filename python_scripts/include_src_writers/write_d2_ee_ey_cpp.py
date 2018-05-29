import os
from single_d2_ee import single_d2_ee, d2_ee_generator

Atoms = {"A":1, "B":2, "C":3, "D":4}
Shells = { "s":0, "p": 0, "d": 0}

src = 'src'

writed = []

def writeD2Vee():

    if not os.path.isdir(src):
        os.mkdir(src)
    for atom1 in Atoms:
        for atom2 in Atoms:
            if Atoms[atom2] >= Atoms[atom1]:
                writeShell(atom1, atom2)
            
def writeShell(atom1, atom2):
    for shell1 in Shells:
        for shell2 in Shells:
            for shell3 in Shells:
                for shell4 in Shells:
                    writeSingleD2Vee(atom1, atom2, shell1, shell2, shell3, shell4)
            
def writeSingleD2Vee(atom1, atom2, shell1, shell2, shell3, shell4):

        shellTable = [shell1, shell2, shell3, shell4]
        global writed
        

        name = "".join(shellTable)+"_"+"".join( [ atom1, atom2 ])
            
	if not name in writed:
		d2_ee_origin = single_d2_ee( shellTable, [atom1, atom2] )
		generator = d2_ee_generator( d2_ee_origin )
		generator.generate_group()
		generator.write_all()
		writed = writed + generator.get_all_names()
       
        
writeD2Vee()
