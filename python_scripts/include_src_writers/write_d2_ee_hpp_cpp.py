import os

Atoms = {"A":1, "B":2, "C":3, "D":4}
Shells = { "s":0, "p": 1, "d": 2}

include = 'include'
src = 'src'

    
def writeD2Vee():
    if not os.path.isdir(include):
        os.mkdir(include)
    if not os.path.isdir(src):
        os.mkdir(src)
    for atom1 in Atoms:
        for atom2 in Atoms:
            if Atoms[atom2] >= Atoms[atom1]:
                writeShell(atom1, atom2)
            
def writeShell(atom1, atom2):
    for shell1 in Shells:
        for shell2 in Shells:
            if shell2 >= shell1 or True:
                for shell3 in Shells:
                    if shell3 >=  shell2 or True:
                        for shell4 in Shells:
                            if shell4 >= shell3 or True:
                                writeSingleD2Vee(atom1, atom2, shell1, shell2, shell3, shell4)
            
def writeSingleD2Vee(atom1, atom2, shell1, shell2, shell3, shell4):
        hppName = "d2_ee_"+shell1+shell2+shell3+shell4+"_"+atom1+atom2+".hpp"


	if atom1 != atom2:
		fileName = "d2_ee_"+shell1+shell2+shell3+shell4+"_"+atom2+atom1+".cpp"
		d2File = open(os.path.join(src, fileName), 'w')
		d2File.write('#include "gto_d2_kit/'+hppName+'"\n')
		d2File.write("void second_derivative_ee_"+str(Shells[shell1])+str(Shells[shell2])+str(Shells[shell3])+str(Shells[shell4])+"_"+str(Atoms[atom2])+str(Atoms[atom1])+"(");
		d2File.write("    const double ae,\n");
		d2File.write("    const double xA,\n");
		d2File.write("    const double yA,\n");
		d2File.write("    const double zA,\n");
		d2File.write("    const double be,\n");
		d2File.write("    const double xB,\n");
		d2File.write("    const double yB,\n");
		d2File.write("    const double zB,\n");
		d2File.write("    const double ce,\n");
		d2File.write("    const double xC,\n");
		d2File.write("    const double yC,\n");
		d2File.write("    const double zC,\n");
		d2File.write("    const double de,\n");
		d2File.write("    const double xD,\n");
		d2File.write("    const double yD,\n");
		d2File.write("    const double zD,\n");
		d2File.write("    const double* const bs,");
		d2File.write("    double* const d2eexx,");
		d2File.write("    double* const d2eexy,");
		d2File.write("    double* const d2eexz,");
		d2File.write("    double* const d2eeyx,");
		d2File.write("    double* const d2eeyy,");
		d2File.write("    double* const d2eeyz,");
		d2File.write("    double* const d2eezx,");
		d2File.write("    double* const d2eezy,");
		d2File.write("    double* const d2eezz){\n");
		d2File.write(" second_derivative_ee_"+str(Shells[shell1])+str(Shells[shell2])+str(Shells[shell3])+str(Shells[shell4])+"_"+str(Atoms[atom1])+str(Atoms[atom2])+"( ae, xA, yA, zA, be, xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, d2eexx, d2eeyx, d2eezx, d2eexy, d2eeyy, d2eezy, d2eexz, d2eeyz, d2eezz);");
		d2File.write( "}\n")
		d2File.close()

        hppFile = open( os.path.join(include, hppName), 'w')
        hppFile.write('#ifndef D2_EE_'+shell1.upper()+shell2.upper()+shell3.upper()+shell4.upper()+'_'+atom1.upper()+atom2.upper()+'_HPP\n')
        hppFile.write('#define D2_EE_'+shell1.upper()+shell2.upper()+shell3.upper()+shell4.upper()+'_'+atom1.upper()+atom2.upper()+'_HPP\n\n')
        hppFile.write("void second_derivative_ee_"+str(Shells[shell1])+str(Shells[shell2])+str(Shells[shell3])+str(Shells[shell4])+"_"+str(Atoms[atom1])+str(Atoms[atom2])+"(");
        hppFile.write("    const double ae,\n");
        hppFile.write("    const double xA,\n");
        hppFile.write("    const double yA,\n");
        hppFile.write("    const double zA,\n");
        hppFile.write("    const double be,\n");
        hppFile.write("    const double xB,\n");
        hppFile.write("    const double yB,\n");
        hppFile.write("    const double zB,\n");
        hppFile.write("    const double ce,\n");
        hppFile.write("    const double xC,\n");
        hppFile.write("    const double yC,\n");
        hppFile.write("    const double zC,\n");
        hppFile.write("    const double de,\n");
        hppFile.write("    const double xD,\n");
        hppFile.write("    const double yD,\n");
        hppFile.write("    const double zD,\n");
        hppFile.write("    const double* const bs,");
        hppFile.write("    double* const d2eexx,");
        hppFile.write("    double* const d2eexy,");
        hppFile.write("    double* const d2eexz,");
        hppFile.write("    double* const d2eeyx,");
        hppFile.write("    double* const d2eeyy,");
        hppFile.write("    double* const d2eeyz,");
        hppFile.write("    double* const d2eezx,");
        hppFile.write("    double* const d2eezy,");
        hppFile.write("    double* const d2eezz);\n");
	if atom1 != atom2:
		hppFile.write("void second_derivative_ee_"+str(Shells[shell1])+str(Shells[shell2])+str(Shells[shell3])+str(Shells[shell4])+"_"+str(Atoms[atom2])+str(Atoms[atom1])+"(");
		hppFile.write("    const double ae,\n");
		hppFile.write("    const double xA,\n");
		hppFile.write("    const double yA,\n");
		hppFile.write("    const double zA,\n");
		hppFile.write("    const double be,\n");
		hppFile.write("    const double xB,\n");
		hppFile.write("    const double yB,\n");
		hppFile.write("    const double zB,\n");
		hppFile.write("    const double ce,\n");
		hppFile.write("    const double xC,\n");
		hppFile.write("    const double yC,\n");
		hppFile.write("    const double zC,\n");
		hppFile.write("    const double de,\n");
		hppFile.write("    const double xD,\n");
		hppFile.write("    const double yD,\n");
		hppFile.write("    const double zD,\n");
		hppFile.write("    const double* const bs,");
		hppFile.write("    double* const d2eexx,");
		hppFile.write("    double* const d2eexy,");
		hppFile.write("    double* const d2eexz,");
		hppFile.write("    double* const d2eeyx,");
		hppFile.write("    double* const d2eeyy,");
		hppFile.write("    double* const d2eeyz,");
		hppFile.write("    double* const d2eezx,");
		hppFile.write("    double* const d2eezy,");
		hppFile.write("    double* const d2eezz);\n");
        hppFile.write('#endif')

def deleteContent(fName):
    with open(fName, "w"):
        pass
        
writeD2Vee()
