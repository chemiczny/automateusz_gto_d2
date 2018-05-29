
suite_names = []
true_values = {}

def write_begin( cpp_file ):
    cpp_file.write( "#include <boost/test/unit_test.hpp>\n")
    cpp_file.write( '#include "gto_d2_kit/d2_ee_matrix.hpp"\n')
    cpp_file.write( '#include "gto_d1_kit/d_ee_matrix.hpp"\n')
    cpp_file.write( '\n using namespace boost::unit_test; \n \n' )

def write_all_functions( cpp_file, write_values = False ):
    shells = [ "s" , "p" , "d" ]
    atoms = [ "A", "B", "C", "D" ]
    for shell1 in shells:
        for shell2 in shells:
            for shell3 in shells:
                for shell4 in shells:
                    for atom1 in atoms:
                        for atom2 in atoms:
                            write_single_func( cpp_file, shell1, shell2, shell3, shell4, atom1, atom2, write_values  )

def generate_suite_names( ):
    shells = [ "s" , "p" , "d" ]
    atoms = [ "A", "B", "C", "D" ]
    for shell1 in shells:
        for shell2 in shells:
            for shell3 in shells:
                for shell4 in shells:
                    for atom1 in atoms:
                        for atom2 in atoms:
                            new_name = 'vee_'+ shell1+ shell2 +shell3+shell4+ '_' + atom1+atom2+'_numerical'
                            suite_names.append( new_name)
                            true_values[ new_name ] = []

def write_single_func( cpp_file, shell1, shell2, shell3, shell4, atom1, atom2, write_values = False ):
    shells2num = { "s" : '0', "p" : '1' , "d" : '2'}
    shells2size = { "s" : 1, "p" : 3 , "d" : 5}
    atoms2num = { "A" : "0", "B" : "1", "C":"2", "D" : "3" }

    minSize = shells2size[ shell1 ] * shells2size[ shell2 ] *shells2size [ shell3 ] * shells2size [ shell4 ]
    maxShell = max( shells2size[shell1] ,  shells2size[shell2]) 
    #minSize = maxShell*maxShell
    arrayInit = minSize * '0,'
    zeroArray = arrayInit[:-1]
    arrayInit = '['+ str(minSize) +']= {'+ zeroArray+ '};\n'
    cpp_file.write( 'void vee_' + shell1 + shell2 +shell3+shell4+'_'+atom1+atom2+ '_numerical(){\n' )
    name = 'vee_' + shell1 + shell2+shell3+shell4+'_' + atom1 + atom2
    cpp_file.write( '\tdouble ae = 0.9; \n')
    cpp_file.write( '\tdouble xA = 1.;\n')
    cpp_file.write( '\tdouble yA = 2.;\n')
    cpp_file.write( '\tdouble zA = 0.2;\n')
    cpp_file.write( '\tdouble be = 0.6;\n')
    cpp_file.write( '\tdouble xB = 0.;\n')
    cpp_file.write( '\tdouble yB = 0.;\n')
    cpp_file.write( '\tdouble zB = 0.;\n')
    cpp_file.write( '\tdouble ce = 0.4;\n')
    cpp_file.write( '\tdouble xC = 0.5;\n')
    cpp_file.write( '\tdouble yC = 2.4;\n')
    cpp_file.write( '\tdouble zC = 5.1;\n')
    cpp_file.write( '\tdouble de = 0.7;\n')
    cpp_file.write( '\tdouble xD = 0.7;\n')
    cpp_file.write( '\tdouble yD = 0.3;\n')
    cpp_file.write( '\tdouble zD = 2.;\n')
    cpp_file.write( '\tdouble bs[] = { 0.369276032831804079142483680055, 0.318261132985649312604972760459e-1, 0.80239809346387912354013014693e-2, 0.321149041108544115706500859421e-2, 0.167803321498522263032822046448e-2, 0.103662780787450103552421696649e-2, 0.715027424553804864528604577758e-3, 0.531811238657941217475959155426e-3,0.417216833292394803678060482496e-3 , 0.340325873169924386532233591377e-3, 0.285862642829352964540776982742e-3,  0.245605917910007743433246275556e-3, 0.214815940934238175607262976026e-3, 0.190601753880735370194833553578e-3};\n')
    cpp_file.write( '\tdouble hxx '+ arrayInit)
    cpp_file.write( '\tdouble hxy '+ arrayInit)
    cpp_file.write( '\tdouble hxz '+ arrayInit)
    cpp_file.write( '\tdouble hyx '+ arrayInit)
    cpp_file.write( '\tdouble hyy '+ arrayInit)
    cpp_file.write( '\tdouble hyz '+ arrayInit)
    cpp_file.write( '\tdouble hzx '+ arrayInit)
    cpp_file.write( '\tdouble hzy '+ arrayInit)
    cpp_file.write( '\tdouble hzz '+ arrayInit)
    
    cpp_file.write( '\tdouble hx '+ arrayInit)
    cpp_file.write( '\tdouble hy '+ arrayInit)
    cpp_file.write( '\tdouble hz '+ arrayInit)
    
    cpp_file.write( '\tdouble hx_dx '+ arrayInit)

    cpp_file.write( '\terid2['+shells2num[ shell1 ] +']['+shells2num[shell2] + ']['+ shells2num[ shell3 ] +']['+shells2num[shell4] + ']['+atoms2num[ atom1 ] +
        ']['+atoms2num[atom2] +']( ae, xA, yA, zA,be,  xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, hxx, hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz );\n')
   
    cpp_file.write( '\terigs['+shells2num[ shell1 ] +']['+shells2num[shell2] + ']['+ shells2num[ shell3 ] +']['+shells2num[shell4] + ']['+atoms2num[ atom1 ] +
        ']('+shells2num[ shell1 ] +' , '+shells2num[shell2] + ' , '+ shells2num[ shell3 ] +' , '+shells2num[shell4] + ', ae, xA, yA, zA,be,  xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs, hx, hy, hz );\n')
        
    cpp_file.write( '\tx'+atom2+'+= 0.0001;\n')
    
    if atom2 == "A":
        cpp_file.write( '\tdouble bs_dr[] = { 0.369276098859500074529060580894, 0.318261299454313034345428308998e-1, 0.802398759732392784507816134606e-2, 0.321149389239991942400609716906e-2, 0.167803536561468182695040051065e-2, 0.103662929129904148911591984902e-2, 0.715028527870752686233144703045e-3,0.531812104232762728020398187381e-3 , 0.417217539346155898949913654672e-3, 0.340326466232086448089132427158e-3, 0.285863152373298914922582281183e-3, 0.245606363575831122634670120409e-3, 0.214816336364335845631565276975e-3,  0.190602108883984862783761693362e-3};\n')
    elif atom2 == "B":
        cpp_file.write( '\tdouble bs_dr[] = { 0.369276076866422117247098436304, 0.318261244005480258443409164701e-1, 0.802398537805852996820038485574e-2, 0.321149273281318953173218794394e-2, 0.167803464926414194198937334322e-2, 0.103662879718695463639695153728e-2, 0.715028160368233985335494309773e-3, 0.531811815919477484133066504978e-3, 0.417217304167546519225793248147e-3, 0.340326268689712073805890698046e-3, 0.285862982649906584725666115994e-3, 0.245606215129526044804176237515e-3,  0.214816204650988619683117770181e-3, 0.190601990636368337852820002078e-3};\n')
    elif atom2 == "C":
        cpp_file.write( '\tdouble bs_dr[] = { 0.369275992744261303635722831967, 0.318261031917182068690851318753e-1, 0.802397688950968305072406864292e-2, 0.321148829746848256321005728094e-2, 0.167803190926970069918249016135e-2, 0.103662690724037950920036102353e-2, 0.71502675469511272964999634774e-3, 0.53181071314005727364538670928e-3, 0.41721640462481546506739645594e-3, 0.340325513103131634903516281367e-3, 0.285862333469118251031248831469e-3, 0.2456056473322059380485435199e-3, 0.214815700856136799878171744617e-3, 0.190601538347053510915041513623e-3 };\n')
    elif atom2 == "D":
        cpp_file.write( '\tdouble bs_dr[] = { 0.369275962643559360321612593176, 0.318260956027489139969654026768e-1, 0.802397385212747217464352677549e-2, 0.321148671040866206548268915241e-2, 0.167803092884206507178448078108e-2, 0.103662623097781318203267540095e-2, 0.715026251715792899808244461838e-3, 0.531810318542477457478747220527e-3, 0.417216082749594858254630880298e-3, 0.340325242738444680248121287318e-3, 0.285862101178656391679227858186e-3, 0.245605444162455526383380782402e-3 , 0.214815520587810845583219300144e-3, 0.190601376508487579696206588877e-3};\n')
    
    cpp_file.write( '\terid2['+shells2num[ shell1 ] +']['+shells2num[shell2] + ']['+ shells2num[ shell3 ] +']['+shells2num[shell4] + ']['+atoms2num[ atom1 ] +
        ']['+atoms2num[atom2] +']( ae, xA, yA, zA,be,  xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs_dr, hxx , hxy, hxz, hyx, hyy,hyz, hzx, hzy, hzz );\n')
   
    cpp_file.write( '\terigs['+shells2num[ shell1 ] +']['+shells2num[shell2] + ']['+ shells2num[ shell3 ] +']['+shells2num[shell4] + ']['+atoms2num[ atom1 ] +
        ']('+shells2num[ shell1 ] +' , '+shells2num[shell2] + ' , '+ shells2num[ shell3 ] +' , '+shells2num[shell4] + ', ae, xA, yA, zA,be,  xB, yB, zB, ce, xC, yC, zC, de, xD, yD, zD, bs_dr, hx_dx, hy, hz );\n')
    
    cpp_file.write( '\tfor (int element_ind = 0; element_ind <'+ str(minSize) +'; element_ind ++) {\n')
    cpp_file.write( '\t\t if ( hxx[element_ind] > 0.01 || hxx[element_ind] < -0.01 ) { \n')
    cpp_file.write( '\t\t\tBOOST_CHECK_CLOSE( hxx[element_ind] /2. , ( hx_dx[element_ind] - hx[element_ind] )/0.0001 , 1 ); \n')
    cpp_file.write( '\t}\n') 
    cpp_file.write( '}\n') 
    cpp_file.write( '}\n') 

def write_suite( cpp_file ):
    cpp_file.write( '\n')
    cpp_file.write( 'test_suite* test_vee_numerical(){ \n')
    cpp_file.write( '\ttest_suite * ts=BOOST_TEST_SUITE("Automateusz vee numerical test");\n')

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

cpp_file = open( 'vee/vee_test_numerical.cpp', 'w')
write_begin( cpp_file )
write_all_functions( cpp_file )
write_suite( cpp_file )
cpp_file.close()
