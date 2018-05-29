import os

Atoms = {"A":1, "B":2, "C":3}
Shells = { "s":0, "p":1, "d":2 }

include = 'include'
src = 'src'


def writeD2Vne():
    if not os.path.isdir(include):
        os.mkdir(include)
    if not os.path.isdir(src):
        os.mkdir(src)
    for atom1 in Atoms:
        for atom2 in Atoms:
            if Atoms[atom2] >= Atoms[atom1] or True:
                writeShell(atom1, atom2)
            
def writeShell(atom1, atom2):
    for shell1 in Shells:
        for shell2 in Shells:
            writeSingleD2Vne(atom1, atom2, shell1, shell2)
            
def writeSingleD2Vne(atom1, atom2, shell1, shell2):
        fileName = "d2_ne_"+shell1+shell2+"_"+atom1+atom2+".ey"
        hppName = "d2_ne_"+shell1+shell2+"_"+atom1+atom2+".hpp"
        hppPath = os.path.join(include, hppName);
        filePath = os.path.join(src , fileName)
        if atom1 <= atom2 :
            d2File = open( filePath, 'w')
            d2File.write('#include "gto_d2_kit/'+"d2_ne_"+shell1+shell2+"_"+atom1+atom2+'.hpp"\n')
            d2File.write('#include <cmath>\n')
            d2File.write('/*\n')
            d2File.write('<?\n')
            d2File.write('	Use("emit_ne_d2.ys");\n')
            d2File.write('?>\n')
            d2File.write('*/\n')
            d2File.write('namespace {\n')
            d2File.write('    const double Pi = M_PI;\n')
            d2File.write('}\n')
            d2File.write('//<?\n')
            d2File.write('EmitVneSecondDerivative('+str(Shells[shell1])+","+str(Shells[shell2])+", {"+str(Atoms[atom1])+" , "+str(Atoms[atom2])+"});\n")
            d2File.write('//?>')
            d2File.close()
        elif atom1 > atom2:
            fileName = "d2_ne_"+shell1+shell2+"_"+atom1+atom2+".cpp"
            filePath = os.path.join(src , fileName)
            d2File = open( filePath, 'w')
            d2File.write('#include "gto_d2_kit/'+"d2_ne_"+shell1+shell2+"_"+atom2+atom1+'.hpp"\n')
            d2File.write("void vne_second_derivative_"+str(Shells[shell1])+str(Shells[shell2])+"_"+str(Atoms[atom1])+str(Atoms[atom2])+"(");
            d2File.write("    double ae, double be,\n");
            d2File.write("    double xA, double yA, double zA,\n");
            d2File.write("    double xB, double yB, double zB,\n");
            d2File.write("    double xC, double yC, double zC,\n");
            d2File.write("    const double* bs,\n");
            d2File.write("    double* const d2nexx,\n");
            d2File.write("    double* const d2nexy,\n");
            d2File.write("    double* const d2nexz,\n");
            d2File.write("    double* const d2neyx,\n");
            d2File.write("    double* const d2neyy,\n");
            d2File.write("    double* const d2neyz,\n");
            d2File.write("    double* const d2nezx,\n");
            d2File.write("    double* const d2nezy,\n");
            d2File.write("    double* const d2nezz,\n");
	    d2File.write("    std::size_t matrix_size,\n"); 
            d2File.write("    std::size_t Ai, std::size_t Bi){\n");
            d2File.write(" vne_second_derivative_"+str(Shells[shell1])+str(Shells[shell2])+"_"+str(Atoms[atom2])+str(Atoms[atom1])+"(");
            d2File.write(" ae, be, xA, yA, zA, xB, yB, zB, xC, yC, zC, bs, d2nexx, d2neyx, d2nezx, d2nexy, d2neyy, d2nezy, d2nexz, d2neyz, d2nezz, matrix_size,  Ai, Bi );\n")
            d2File.write("}\n")
            
            
            d2File.close()
        
        if atom1 <= atom2:
            hppFile = open( hppPath, 'w')
            hppFile.write('#ifndef D2_NE_'+shell1.upper()+shell2.upper()+'_'+atom1.upper()+atom2.upper()+'_HPP\n')
            hppFile.write('#define D2_NE_'+shell1.upper()+shell2.upper()+'_'+atom1.upper()+atom2.upper()+'_HPP\n\n')

	    hppFile.write('#include <cstdlib>\n')
            hppFile.write("void vne_second_derivative_"+str(Shells[shell1])+str(Shells[shell2])+"_"+str(Atoms[atom1])+str(Atoms[atom2])+"(");
            hppFile.write("    double ae, double be,\n");
            hppFile.write("    double xA, double yA, double zA,\n");
            hppFile.write("    double xB, double yB, double zB,\n");
            hppFile.write("    double xC, double yC, double zC,\n");
            hppFile.write("    const double* bs,\n");
            hppFile.write("    double* const d2nexx,\n");
            hppFile.write("    double* const d2nexy,\n");
            hppFile.write("    double* const d2nexz,\n");
            hppFile.write("    double* const d2neyx,\n");
            hppFile.write("    double* const d2neyy,\n");
            hppFile.write("    double* const d2neyz,\n");
            hppFile.write("    double* const d2nezx,\n");
            hppFile.write("    double* const d2nezy,\n");
            hppFile.write("    double* const d2nezz,\n");
	    hppFile.write("    std::size_t matrix_size,\n");
            hppFile.write("    std::size_t Ai, std::size_t Bi);\n");
            if atom1 != atom2:
                hppFile.write("\nvoid vne_second_derivative_"+str(Shells[shell1])+str(Shells[shell2])+"_"+str(Atoms[atom2])+str(Atoms[atom1])+"(");
                hppFile.write("    double ae, double be,\n");
                hppFile.write("    double xA, double yA, double zA,\n");
                hppFile.write("    double xB, double yB, double zB,\n");
                hppFile.write("    double xC, double yC, double zC,\n");
                hppFile.write("    const double* bs,\n");
                hppFile.write("    double* const d2nexx,\n");
                hppFile.write("    double* const d2nexy,\n");
                hppFile.write("    double* const d2nexz,\n");
                hppFile.write("    double* const d2neyx,\n");
                hppFile.write("    double* const d2neyy,\n");
                hppFile.write("    double* const d2neyz,\n");
                hppFile.write("    double* const d2nezx,\n");
                hppFile.write("    double* const d2nezy,\n");
                hppFile.write("    double* const d2nezz,\n");
		hppFile.write("	   std::size_t matrix_size,\n");
                hppFile.write("    std::size_t Ai, std::size_t Bi);\n");
            hppFile.write('#endif')

        
writeD2Vne()
