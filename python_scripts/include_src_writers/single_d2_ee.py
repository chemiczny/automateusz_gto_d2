from copy import deepcopy
import os

class single_d2_ee:
    def __init__( self, shells_init, atoms_init, order_init = { 0:0, 1:1, 2:2, 3:3}, reverse_init = False ):
        self.shells = shells_init
        self.atoms = atoms_init
        self.order = order_init
        self.reverse = reverse_init

    def transposition( self, trans_case ):
        if trans_case == "A-B":
            self.swap_atoms( 0, 1 )
        elif trans_case == "C-D":
            self.swap_atoms( 2, 3 )
        elif trans_case == "AB-CD":
            self.swap_atoms( 0, 2 )
            self.swap_atoms( 1, 3 )
        else:
            print "Niepoprawny klucz permutacji"

    def swap_atoms( self, ind_a, ind_b ):
        ind2atom = [ "A", "B", "C", "D" ]
        atom2ind = { "A" : 0, "B" : 1,"C" : 2, "D" : 3 }

        self.order[ ind_a ], self.order[ ind_b ] = self.order[ ind_b ] , self.order[ ind_a ]
        self.shells[ self.order[ ind_a ] ], self.shells[self.order[ ind_b ] ] = self.shells[self.order[ind_b]] , self.shells[self.order[ind_a]]
        for atom_ind in range(len(self.atoms)):
            if self.atoms[atom_ind] == ind2atom[ self.order[ ind_a] ]:
                self.atoms[ atom_ind ] = ind2atom[ self.order[ ind_b ] ]
            elif self.atoms[atom_ind] ==ind2atom[ self.order[ ind_b ] ]:
                self.atoms[ atom_ind ] = ind2atom[ self.order[ ind_a  ]]

        if self.atoms[0] > self.atoms[1]:
            self.atoms[0], self.atoms[1] = self.atoms[1], self.atoms[0]
            self.reverse = not self.reverse


    def get_name( self ):
        return "".join( self.shells )+'_'+"".join( self.atoms ) 

    def write (self, shells_incl, atoms_incl):
        kernel = ''.join( self.shells) + '_' + ''.join( self.atoms )
        kernel_incl = ''.join( shells_incl) + '_' + ''.join( atoms_incl )
        print "kernel "+kernel
        if not os.path.isdir('src'):
            os.mkdir('src')
        file_name = 'src/d2_ee_'+ kernel + '.cpp'
        ey_file = open( file_name, 'w' )

        shells2num = { 's':'0', 'p':'1', 'd':'2'}
        atoms2num = { 'A' : '1', 'B': '2', 'C' : '3', 'D':'4'}

        include_name = 'gto_d2_kit/d2_ee_' + kernel + '.hpp'
        include_name_perm = 'gto_d2_kit/d2_ee_' + kernel_incl + '.hpp'

        ey_file.write( '#include "'+ include_name + '"\n')
        ey_file.write( '#include "'+ include_name_perm + '"\n\n')

        ey_file.write('void second_derivative_ee_'+shells2num[ self.shells[0] ] +shells2num[ self.shells[1] ]
            + shells2num[ self.shells[2] ] +shells2num[ self.shells[3] ] +'_' + atoms2num[ self.atoms[0] ]+
            atoms2num[ self.atoms[1] ] +'( \n')

        ey_file.write('     const double ae,             \n')
        ey_file.write('     const double xA,	     \n')
        ey_file.write('     const double yA,             \n')
        ey_file.write('     const double zA,	     \n')
        ey_file.write('     const double be,             \n')
        ey_file.write('     const double xB,	     \n')
        ey_file.write('     const double yB,             \n')
        ey_file.write('     const double zB,	     \n')
        ey_file.write('     const double ce,             \n')
        ey_file.write('     const double xC,	     \n')
        ey_file.write('     const double yC,             \n')
        ey_file.write('     const double zC,	     \n')
        ey_file.write('     const double de,             \n')
        ey_file.write('     const double xD,	     \n')
        ey_file.write('     const double yD,             \n')
        ey_file.write('     const double zD,	     \n')
        ey_file.write('     const double* const bs, 	    \n')
        ey_file.write('     double* const d2eexx,   	    \n')
        ey_file.write('     double* const d2eexy,   	    \n')
        ey_file.write('     double* const d2eexz,   	    \n')
        ey_file.write('     double* const d2eeyx,		  \n')
        ey_file.write('     double* const d2eeyy,		  \n')
        ey_file.write('     double* const d2eeyz,		  \n')
        ey_file.write('     double* const d2eezx,		  \n')
        ey_file.write('     double* const d2eezy,		  \n')
        ey_file.write('     double* const d2eezz)		  \n')
        ey_file.write(' { 		  \n')

        args = [ 'ae, xA, yA, zA, ',  'be, xB, yB, zB, ',  'ce, xC, yC, zC, ',  'de, xD, yD, zD, ' ]

        if self.have2rewrite():
            shells2size = { "s" : 1, "p" : 3 , "d" : 5}
            minSize = 1
            for shell in self.shells:
                minSize = minSize * shells2size[ shell ]

            arrayInit = '['+ str(minSize) +']= {};\n'

            ey_file.write( '\tdouble txx '+ arrayInit)
            ey_file.write( '\tdouble txy '+ arrayInit)
            ey_file.write( '\tdouble txz '+ arrayInit)
            ey_file.write( '\tdouble tyx '+ arrayInit)
            ey_file.write( '\tdouble tyy '+ arrayInit)
            ey_file.write( '\tdouble tyz '+ arrayInit)
            ey_file.write( '\tdouble tzx '+ arrayInit)
            ey_file.write( '\tdouble tzy '+ arrayInit)
            ey_file.write( '\tdouble tzz '+ arrayInit)

            ey_file.write('\tsecond_derivative_ee_'+shells2num[ shells_incl[0] ] +shells2num[ shells_incl[1] ]
                + shells2num[ shells_incl[2] ] +shells2num[ shells_incl[3] ] +'_' + atoms2num[ atoms_incl[0] ]+
                atoms2num[ atoms_incl[1] ] +'( ')

            for atom_ind in self.order:
                ey_file.write( args[ self.order[ atom_ind ] ] )

            if self.reverse:
                ey_file.write(' bs, txx, tyx, tzx, txy, tyy, tzy, txz, tyz, tzz );\n ')
            else:
                ey_file.write(' bs, txx, txy, txz, tyx, tyy, tyz, tzx, tzy, tzz );\n ')

            iterators = ['i', 'j', 'k', 'l']
            iterator2shell = { 'i' : self.shells[0], 'j' : self.shells[1], 'k' : self.shells[2], 'l' : self.shells[3] }
            iterators_cutted = []
            atom2it = { 'A': 'i',  'B' : 'j', 'C' : 'k', 'D': 'l'}
            tabNo = 1
            shells_without_s = self.get_shells_without_s()
            for ind in shells_without_s:
                ey_file.write( tabNo * '\t'+ "for( int "+str(iterators[ind]) +" = 0 ; "+str(iterators[ind])+"<"+ str(shells2size[self.shells[ind]])+"; "+ str(iterators[ind])+"++){ \n" )
                iterators_cutted.append( iterators[ind] )
                tabNo = tabNo +1

            iterators_cutted.sort()
            writeFrom = ""
            writeTo = ""

            lastFromSize = 0
            lastToSize = 0
            for ind in range(len(iterators_cutted)):
                if not writeFrom:
                    writeFrom = str(iterators[shells_without_s[ind]])
                    lastFromSize = str( shells2size[ iterator2shell[ iterators[shells_without_s[ind]]  ] ] )
                    writeTo = str(iterators_cutted[ind])
                    lastToSize = str( shells2size[ iterator2shell[iterators_cutted[ind]  ] ] )
                else:
                    lastFromSize = str( shells2size[ iterator2shell[ iterators[shells_without_s[ind]]  ] ] )
                    writeFrom = "("+writeFrom+")*"+ lastFromSize  +"+"+str(iterators[shells_without_s[ind]])
                    
                    lastToSize = str( shells2size[ iterator2shell[iterators_cutted[ind]  ] ] )
                    writeTo = "("+writeTo+")*"+ lastToSize +"+"+str(iterators_cutted[ind])
                    

            ey_file.write( tabNo*'\t'+"int destinyInd = "+writeTo+";\n")
            ey_file.write( tabNo*'\t'+ "int sourceInd = "+writeFrom+";\n")

            coords = ['xx', 'xy', 'xz', 'yx', 'yy', 'yz', 'zx', 'zy', 'zz']

            for coord in coords:
                ey_file.write( tabNo*'\t'+"d2ee"+coord+"[ destinyInd ] += t"+coord+"[ sourceInd ]; \n")
            for i in range( len(iterators_cutted), 0, -1):
                ey_file.write( i*'\t'+'}\n')

        else:

            ey_file.write('\tsecond_derivative_ee_'+shells2num[ shells_incl[0] ] +shells2num[ shells_incl[1] ]
                + shells2num[ shells_incl[2] ] +shells2num[ shells_incl[3] ] +'_' + atoms2num[ atoms_incl[0] ]+
                atoms2num[ atoms_incl[1] ] +'( ')
            for atom_ind in self.order:
                ey_file.write( args[ self.order[ atom_ind ] ] )

            if self.reverse:
                ey_file.write(' bs, d2eexx, d2eeyx, d2eezx, d2eexy, d2eeyy, d2eezy, d2eexz, d2eeyz, d2eezz );\n ')
            else:
                ey_file.write(' bs, d2eexx, d2eexy, d2eexz, d2eeyx, d2eeyy, d2eeyz, d2eezx, d2eezy, d2eezz );\n ')
        ey_file.write( "}\n")
        ey_file.close()

    def have2rewrite(self):
        shells_without_s = self.get_shells_without_s()
##        print str(shells_without_s)+self.get_name()+str( self.order)
        if shells_without_s != sorted( shells_without_s ):
            return True

    def get_shells_without_s(self):
        shells_without_s = []
        for i in range(4):
            if self.shells[ self.order[i] ] != 's':
                shells_without_s.append( self.order[ i ] )

        return shells_without_s
    def write_ey_gen( self, shells, atoms):
        shells2num = { 's':'0', 'p':'1', 'd':'2'}
        
        shells2int = { 's':0, 'p':1, 'd':2}
        totalL = shells2int[shells[0]]+shells2int[shells[1]]+shells2int[shells[2]]+shells2int[shells[3]]
        atoms2num = { 'A' : '1', 'B': '2', 'C' : '3', 'D':'4'}
        kernel = ''.join( shells) + '_' + ''.join( atoms )
        if totalL < 6:
            file_name = 'src/d2_ee_'+ kernel + '.ey'
            ey_file = open( file_name, 'w' )
    
            include_name = 'gto_d2_kit/d2_ee_' + kernel + '.hpp'
    
            ey_file.write( '#include "'+ include_name + '"\n')
            ey_file.write('#include <cmath>\n')
            ey_file.write('/*\n')
            ey_file.write('<?\n')
            ey_file.write('Use("emit_eri_d2.ys");\n')
            ey_file.write('?>\n')
            ey_file.write('*/\n')
            ey_file.write('namespace { \n')
            ey_file.write('    const double Pi = M_PI;\n')
            ey_file.write('}\n')
            ey_file.write('//<?\n')
            ey_file.write('EmitD2ERI( '+shells2num[ shells[0] ] +' , '+shells2num[ shells[1] ] +' , '
                + shells2num[ shells[2] ] +' , '+shells2num[ shells[3] ] +' , {' + atoms2num[ atoms[0] ]+ ' , '+
                atoms2num[ atoms[1] ] +' } ); \n')
            ey_file.write('//?>\n')
            ey_file.close()
        else:
            file_name = 'src/d2_ee_'+ kernel + '.cpp'
            ey_file = open( file_name, 'w' )
    
           
            atoms2num = { 'A' : '1', 'B': '2', 'C' : '3', 'D':'4'}
    
            include_name = 'gto_d2_kit/d2_ee_' + kernel + '.hpp'
    
            ey_file.write( '#include "'+ include_name + '"\n')
            ey_file.write( '#include "gto_d2_kit/d2_ee_' + kernel + '_xx.hpp"\n')
            ey_file.write( '#include "gto_d2_kit/d2_ee_' + kernel + '_xy.hpp"\n')
            ey_file.write( '#include "gto_d2_kit/d2_ee_' + kernel + '_xz.hpp"\n')
            
            ey_file.write( '#include "gto_d2_kit/d2_ee_' + kernel + '_yx.hpp"\n')
            ey_file.write( '#include "gto_d2_kit/d2_ee_' + kernel + '_yy.hpp"\n')
            ey_file.write( '#include "gto_d2_kit/d2_ee_' + kernel + '_yz.hpp"\n')
            
            ey_file.write( '#include "gto_d2_kit/d2_ee_' + kernel + '_zx.hpp"\n')
            ey_file.write( '#include "gto_d2_kit/d2_ee_' + kernel + '_zy.hpp"\n')
            ey_file.write( '#include "gto_d2_kit/d2_ee_' + kernel + '_zz.hpp"\n')
            
            nameKernel = shells2num[ self.shells[0] ] +shells2num[ self.shells[1] ] + shells2num[ self.shells[2] ] +shells2num[ self.shells[3] ] +'_' + atoms2num[ self.atoms[0] ] + atoms2num[ self.atoms[1] ]
            ey_file.write('void second_derivative_ee_'+ nameKernel +'( \n')

            ey_file.write('     const double ae,             \n')
            ey_file.write('     const double xA,	     \n')
            ey_file.write('     const double yA,             \n')
            ey_file.write('     const double zA,	     \n')
            ey_file.write('     const double be,             \n')
            ey_file.write('     const double xB,	     \n')
            ey_file.write('     const double yB,             \n')
            ey_file.write('     const double zB,	     \n')
            ey_file.write('     const double ce,             \n')
            ey_file.write('     const double xC,	     \n')
            ey_file.write('     const double yC,             \n')
            ey_file.write('     const double zC,	     \n')
            ey_file.write('     const double de,             \n')
            ey_file.write('     const double xD,	     \n')
            ey_file.write('     const double yD,             \n')
            ey_file.write('     const double zD,	     \n')
            ey_file.write('     const double* const bs, 	    \n')
            ey_file.write('     double* const d2eexx,   	    \n')
            ey_file.write('     double* const d2eexy,   	    \n')
            ey_file.write('     double* const d2eexz,   	    \n')
            ey_file.write('     double* const d2eeyx,		  \n')
            ey_file.write('     double* const d2eeyy,		  \n')
            ey_file.write('     double* const d2eeyz,		  \n')
            ey_file.write('     double* const d2eezx,		  \n')
            ey_file.write('     double* const d2eezy,		  \n')
            ey_file.write('     double* const d2eezz)		  \n')
            ey_file.write(' { 		  \n')
            
            ey_file.write('   second_derivative_ee_'+ nameKernel +'_11( ae, xA, yA, zA, be, xB, yB, zB, ' +
            'ce, xC, yC, zC, de, xD, yD, zD, bs, d2eexx );\n')     
            ey_file.write('   second_derivative_ee_'+ nameKernel +'_12( ae, xA, yA, zA, be, xB, yB, zB, ' +
            'ce, xC, yC, zC, de, xD, yD, zD, bs, d2eexy );\n') 
            ey_file.write('   second_derivative_ee_'+ nameKernel +'_13( ae, xA, yA, zA, be, xB, yB, zB, ' +
            'ce, xC, yC, zC, de, xD, yD, zD, bs, d2eexz );\n') 
            
            ey_file.write('   second_derivative_ee_'+ nameKernel +'_21( ae, xA, yA, zA, be, xB, yB, zB, ' +
            'ce, xC, yC, zC, de, xD, yD, zD, bs, d2eeyx );\n') 
            ey_file.write('   second_derivative_ee_'+ nameKernel +'_22( ae, xA, yA, zA, be, xB, yB, zB, ' +
            'ce, xC, yC, zC, de, xD, yD, zD, bs, d2eeyy );\n') 
            ey_file.write('   second_derivative_ee_'+ nameKernel +'_23( ae, xA, yA, zA, be, xB, yB, zB, ' +
            'ce, xC, yC, zC, de, xD, yD, zD, bs, d2eeyz );\n') 
            
            ey_file.write('   second_derivative_ee_'+ nameKernel +'_31( ae, xA, yA, zA, be, xB, yB, zB, ' +
            'ce, xC, yC, zC, de, xD, yD, zD, bs, d2eezx );\n') 
            ey_file.write('   second_derivative_ee_'+ nameKernel +'_32( ae, xA, yA, zA, be, xB, yB, zB, ' +
            'ce, xC, yC, zC, de, xD, yD, zD, bs, d2eezy );\n') 
            ey_file.write('   second_derivative_ee_'+ nameKernel +'_33( ae, xA, yA, zA, be, xB, yB, zB, ' +
            'ce, xC, yC, zC, de, xD, yD, zD, bs, d2eezz );\n') 
            
            ey_file.write(' }\n')
            ey_file.close()
            
            coord2case = { "x" : 1, "y" : 2, "z" : 3 }
            for case in [ "xx", "xy", "xz", "yx", "yy", "yz", "zx", "zy", "zz" ]:
                ey_file = open( 'src/d2_ee_'+ kernel + '_'+case+'.ey', 'w' )
                include_name = 'gto_d2_kit/d2_ee_' + kernel +"_"+case+ '.hpp'
    
                ey_file.write( '#include "'+ include_name + '"\n')
                ey_file.write('#include <cmath>\n')
                ey_file.write('/*\n')
                ey_file.write('<?\n')
                ey_file.write('Use("emit_single_eri_d2.ys");\n')
                ey_file.write('?>\n')
                ey_file.write('*/\n')
                ey_file.write('namespace { \n')
                ey_file.write('    const double Pi = M_PI;\n')
                ey_file.write('}\n')
                ey_file.write('//<?\n')
                ey_file.write('EmitSingleD2ERI( '+shells2num[ shells[0] ] +' , '+shells2num[ shells[1] ] +' , '
                    + shells2num[ shells[2] ] +' , '+shells2num[ shells[3] ] +' , {' + atoms2num[ atoms[0] ]+ ' , '+
                    atoms2num[ atoms[1] ] +'} , {'+str(coord2case[case[0]])+','+ str(coord2case[case[1]])+ ' } ); \n')
                ey_file.write('//?>\n')
                ey_file.close()
                
                hpp_file = open( 'include/d2_ee_'+ kernel + '_'+case+'.hpp', 'w' )
                
                hpp_file.write('#ifndef D2_EE_'+shells[0].upper()+shells[1].upper()+shells[2].upper()+shells[3].upper()+'_'+atoms[0].upper()+atoms[1].upper()+'_'+str(coord2case[case[0]]).upper()+ str(coord2case[case[1]]).upper()+'_HPP\n')
                hpp_file.write('#define D2_EE_'+shells[0].upper()+shells[1].upper()+shells[2].upper()+shells[3].upper()+'_'+atoms[0].upper()+atoms[1].upper()+'_'+str(coord2case[case[0]]).upper()+ str(coord2case[case[1]]).upper()+'_HPP\n')
                
                hpp_file.write('void second_derivative_ee_'+ nameKernel+"_"+str(coord2case[case[0]])+ str(coord2case[case[1]]) +'( \n')

                hpp_file.write('     const double ae,             \n')
                hpp_file.write('     const double xA,	     \n')
                hpp_file.write('     const double yA,             \n')
                hpp_file.write('     const double zA,	     \n')
                hpp_file.write('     const double be,             \n')
                hpp_file.write('     const double xB,	     \n')
                hpp_file.write('     const double yB,             \n')
                hpp_file.write('     const double zB,	     \n')
                hpp_file.write('     const double ce,             \n')
                hpp_file.write('     const double xC,	     \n')
                hpp_file.write('     const double yC,             \n')
                hpp_file.write('     const double zC,	     \n')
                hpp_file.write('     const double de,             \n')
                hpp_file.write('     const double xD,	     \n')
                hpp_file.write('     const double yD,             \n')
                hpp_file.write('     const double zD,	     \n')
                hpp_file.write('     const double* const bs, 	    \n')
                hpp_file.write('     double* const d2ee);		  \n')
                
                hpp_file.write('#endif')
                hpp_file.close()
                
                
                

class d2_ee_generator:
    def __init__( self, origin_d2_ee_init ):
        self.origin_d2_ee = origin_d2_ee_init
        self.origin_name = self.origin_d2_ee.get_name()
        print "Unikalna calka: "+self.origin_name
        self.d2_ee_group = []
        self.names = []

    def get_transformed( self, d2_ee, trans_case ):
        shells_init = deepcopy( d2_ee.shells)
        atoms_init = deepcopy( d2_ee.atoms)
        order_init = deepcopy( d2_ee.order )
        reverse_init = deepcopy( d2_ee.reverse) 
        d2_ee_trans = single_d2_ee( shells_init , atoms_init, order_init, reverse_init )
        
        d2_ee_trans.transposition( trans_case )
        return d2_ee_trans

    def generate_group( self ):
        
        should_continue = self.make_new_elements_from( self.origin_d2_ee )

        while should_continue:
            should_continue = False
            for d2_ee in self.d2_ee_group:
                new_elements_founded = self.make_new_elements_from( d2_ee )
                if new_elements_founded:
                    should_continue = True
                
    def make_new_elements_from( self, d2_ee):
        permutation_keys = [ "A-B", "C-D", "AB-CD" ]
        
        new_elements_founded = False
        for key in permutation_keys:
            new_d2_ee = self.get_transformed( d2_ee, key )
            new_name = new_d2_ee.get_name()
            if not new_name in self.names and new_name != self.origin_name:
                self.names.append( new_name )
                self.d2_ee_group.append( new_d2_ee )
                new_elements_founded = True

        return new_elements_founded

    def print_all_elements( self):
        print self.origin_name

        for element in self.d2_ee_group:
            print element.get_name()

    def get_all_names(self):
        all_elements = [ self.origin_name ] + self.names
        return all_elements

    def write_all( self ):
        for element in self.d2_ee_group:
            element.write( self.origin_d2_ee.shells , self.origin_d2_ee.atoms )
            
        self.origin_d2_ee.write_ey_gen( self.origin_d2_ee.shells , self.origin_d2_ee.atoms )

#--- Main
if __name__ == "__main__":
    d2_ee = single_d2_ee( [ "p", "p", "s", "s" ], [ "A", "A"] )
    generator = d2_ee_generator( d2_ee )
    generator.generate_group()
    generator.print_all_elements()
    print generator.get_all_names()
    generator.write_all()

    d2_ee = single_d2_ee( [ "p", "p", "s", "s" ], [ "D", "D"], { 0: 3, 1:2, 2:0, 3:1} )
    print d2_ee.get_shells_without_s()

