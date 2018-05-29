
suite_names = []
true_values = {}

def write_begin( cpp_file ):
    cpp_file.write( "#include <boost/test/unit_test.hpp>\n")
    cpp_file.write( '#include "gto_d2_kit/d2_overlap_matrix.hpp"\n')
    cpp_file.write( '\n using namespace boost::unit_test; \n \n' )

def write_all_functions( cpp_file, write_values = False ):
    shells = [ "s" , "p" ]
    for shell1 in shells:
        for shell2 in shells:
            write_single_func( cpp_file, shell1, shell2, write_values  )

def generate_suite_names( ):
    shells = [ "s" , "p" ]
    for shell1 in shells:
        for shell2 in shells:
            suite_names.append( 'overlap_'+ shell1+ shell2)
            true_values[ 'overlap_'+ shell1+ shell2 ] = []

def write_single_func( cpp_file, shell1, shell2, write_values = False ):
    shells2num = { "s" : '0', "p" : '1' }
    shells2size = { "s" : 1, "p" : 3 }
    minSize = shells2size[ shell1 ] * shells2size[ shell2 ]
    maxShell = max( shells2size[shell1] ,  shells2size[shell2])
    #minSize = maxShell*maxShell
    arrayInit = minSize * '0,'
    zeroArray = arrayInit[:-1]
    arrayInit = '['+ str(minSize) +']= {'+ zeroArray+ '};\n'
    cpp_file.write( 'void overlap_' + shell1 + shell2 + '(){\n' )
    name = 'overlap_' + shell1 + shell2
    cpp_file.write( '\tdouble ae = 1.1; \n')
    cpp_file.write( '\tdouble be = 1.7;\n')
    cpp_file.write( '\tdouble cc = ae*be/(ae+be);\n')
    cpp_file.write( '\tdouble xAB = 1.1;\n')
    cpp_file.write( '\tdouble yAB = 2.3;\n')
    cpp_file.write( '\tdouble zAB = 1.6;\n')
    cpp_file.write( '\tdouble hxx'+ arrayInit)
    cpp_file.write( '\tdouble hxy'+ arrayInit)
    cpp_file.write( '\tdouble hxz'+ arrayInit)
    cpp_file.write( '\tdouble hyy'+ arrayInit)
    cpp_file.write( '\tdouble hyz'+ arrayInit)
    cpp_file.write( '\tdouble hzz'+ arrayInit)
    cpp_file.write( '\tbool same_atom = true;\n')
    cpp_file.write( '\tstd::size_t matrix_size ='+str(maxShell)+ ' ; \n')
    cpp_file.write( '\tstd::size_t Ai = 0 ;\n')
    cpp_file.write( '\tstd::size_t Bi = 0 ;\n')
    cpp_file.write( '\tad2s['+shells2num[ shell1 ] +']['+shells2num[shell2] + ']( ae, be, cc, xAB, yAB, zAB, hxx, hxy, hxz, hyy, hyz, hzz, same_atom, matrix_size, Ai, Bi );\n')
    cpp_file.write( '\tdouble* result [] = { hxx, hxy, hxz, hyy, hyz, hzz };\n')
    if write_values:
        cpp_file.write( '\tdouble true_result ['+str(minSize*6)+']  = {')
        values_s = ""
        for value in true_values[name]:
            values_s = values_s + value + ' ,' 

        values_s = values_s[:-1]
        cpp_file.write( values_s + '};\n')
    else:
        cpp_file.write( '\tdouble true_result ['+str(6*minSize)+'] = {')
        arrayInit100 = minSize * '100,'
        hundArray = arrayInit100[:-1]
        hundArray2d = 6 * ( hundArray+',')
        hundArray2d = hundArray2d[:-1]
        cpp_file.write( hundArray2d + '};\n')
    cpp_file.write( '\tfor (int test_ind = 0; test_ind < 6; test_ind ++) \n')
    cpp_file.write( '\t\tfor (int element_ind = 0; element_ind <'+ str(minSize) +'; element_ind ++) \n')
    cpp_file.write( '\t\t\tBOOST_CHECK_CLOSE( result[test_ind][element_ind], true_result[test_ind*'+str(minSize)+'+element_ind] , 0.00001); \n')
    cpp_file.write( '}\n') 

def write_suite( cpp_file ):
    cpp_file.write( '\n')
    cpp_file.write( 'test_suite* test_overlap(){ \n')
    cpp_file.write( '\ttest_suite * ts=BOOST_TEST_SUITE("Automateusz overlap test");\n')

    for suite in suite_names:
        cpp_file.write( '\tts->add( BOOST_TEST_CASE( & ' + suite + '));\n')
    cpp_file.write( '\treturn ts;\n')
    cpp_file.write( '}')

def get_true_values( log_file ):
    line = log_file.readline()
    while not "error" in line:
        line = log_file.readline()

    while "error" in line:
        func_name = line.split( '"')[1]
        func_name = func_name.strip()

        true_value = line.split( '{')[2]
        true_value = true_value.split( '}')[0]

        true_values[func_name].append( true_value )
        line = log_file.readline()

generate_suite_names()

log_file = open( 'overlap/LastTest.log', 'r' )
get_true_values( log_file )
log_file.close()
print true_values

cpp_file = open( 'overlap/overlap_test.cpp', 'w')
write_begin( cpp_file )
write_all_functions( cpp_file , True)
write_suite( cpp_file )
cpp_file.close()
