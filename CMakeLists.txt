cmake_minimum_required (VERSION 3.5)

project (GTO_D2_KIT VERSION 0.1)

function(copy_files_if_different FILES  FROM_DIR TO_DIR TARGETS )
	foreach (F ${${FILES}})
	  get_filename_component (T "${F}" NAME)
	  set (TO "${TO_DIR}/${T}")
	  set (FROM "${FROM_DIR}/${T}" ) 
	  add_custom_command (
	    OUTPUT "${TO}"
	    COMMAND cmake -E copy_if_different  ${FROM} ${TO}
	    DEPENDS "${FROM}"
	    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
	    COMMENT "Copying from ${FROM} to ${TO}")
	  list (APPEND ${TARGETS} "${TO}")
	endforeach ()
set( ${TARGETS} ${${TARGETS}} PARENT_SCOPE) 
endfunction(copy_files_if_different)

set (SRCS
		src/d2_ee_dddd_AA_xx.ey
		src/d2_ee_dddd_AA_xy.ey
		src/d2_ee_dddd_AA_xz.ey
		src/d2_ee_dddd_AA_yx.ey
		src/d2_ee_dddd_AA_yy.ey
		src/d2_ee_dddd_AA_yz.ey
		src/d2_ee_dddd_AA_zx.ey
		src/d2_ee_dddd_AA_zy.ey
		src/d2_ee_dddd_AA_zz.ey
		src/d2_ee_dddd_AB_xx.ey
		src/d2_ee_dddd_AB_xy.ey
		src/d2_ee_dddd_AB_xz.ey
		src/d2_ee_dddd_AB_yx.ey
		src/d2_ee_dddd_AB_yy.ey
		src/d2_ee_dddd_AB_yz.ey
		src/d2_ee_dddd_AB_zx.ey
		src/d2_ee_dddd_AB_zy.ey
		src/d2_ee_dddd_AB_zz.ey
		src/d2_ee_dddd_AC_xx.ey
		src/d2_ee_dddd_AC_xy.ey
		src/d2_ee_dddd_AC_xz.ey
		src/d2_ee_dddd_AC_yx.ey
		src/d2_ee_dddd_AC_yy.ey
		src/d2_ee_dddd_AC_yz.ey
		src/d2_ee_dddd_AC_zx.ey
		src/d2_ee_dddd_AC_zy.ey
		src/d2_ee_dddd_AC_zz.ey
		src/d2_ee_ddpd_AA_xx.ey
		src/d2_ee_ddpd_AA_xy.ey
		src/d2_ee_ddpd_AA_xz.ey
		src/d2_ee_ddpd_AA_yx.ey
		src/d2_ee_ddpd_AA_yy.ey
		src/d2_ee_ddpd_AA_yz.ey
		src/d2_ee_ddpd_AA_zx.ey
		src/d2_ee_ddpd_AA_zy.ey
		src/d2_ee_ddpd_AA_zz.ey
		src/d2_ee_ddpd_AB_xx.ey
		src/d2_ee_ddpd_AB_xy.ey
		src/d2_ee_ddpd_AB_xz.ey
		src/d2_ee_ddpd_AB_yx.ey
		src/d2_ee_ddpd_AB_yy.ey
		src/d2_ee_ddpd_AB_yz.ey
		src/d2_ee_ddpd_AB_zx.ey
		src/d2_ee_ddpd_AB_zy.ey
		src/d2_ee_ddpd_AB_zz.ey
		src/d2_ee_ddpp_AA_xx.ey
		src/d2_ee_ddpp_AA_xy.ey
		src/d2_ee_ddpp_AA_xz.ey
		src/d2_ee_ddpp_AA_yx.ey
		src/d2_ee_ddpp_AA_yy.ey
		src/d2_ee_ddpp_AA_yz.ey
		src/d2_ee_ddpp_AA_zx.ey
		src/d2_ee_ddpp_AA_zy.ey
		src/d2_ee_ddpp_AA_zz.ey
		src/d2_ee_ddpp_AB_xx.ey
		src/d2_ee_ddpp_AB_xy.ey
		src/d2_ee_ddpp_AB_xz.ey
		src/d2_ee_ddpp_AB_yx.ey
		src/d2_ee_ddpp_AB_yy.ey
		src/d2_ee_ddpp_AB_yz.ey
		src/d2_ee_ddpp_AB_zx.ey
		src/d2_ee_ddpp_AB_zy.ey
		src/d2_ee_ddpp_AB_zz.ey
		src/d2_ee_ddsd_AA_xx.ey
		src/d2_ee_ddsd_AA_xy.ey
		src/d2_ee_ddsd_AA_xz.ey
		src/d2_ee_ddsd_AA_yx.ey
		src/d2_ee_ddsd_AA_yy.ey
		src/d2_ee_ddsd_AA_yz.ey
		src/d2_ee_ddsd_AA_zx.ey
		src/d2_ee_ddsd_AA_zy.ey
		src/d2_ee_ddsd_AA_zz.ey
		src/d2_ee_ddsd_AB_xx.ey
		src/d2_ee_ddsd_AB_xy.ey
		src/d2_ee_ddsd_AB_xz.ey
		src/d2_ee_ddsd_AB_yx.ey
		src/d2_ee_ddsd_AB_yy.ey
		src/d2_ee_ddsd_AB_yz.ey
		src/d2_ee_ddsd_AB_zx.ey
		src/d2_ee_ddsd_AB_zy.ey
		src/d2_ee_ddsd_AB_zz.ey
		src/d2_ee_dpdd_AA_xx.ey
		src/d2_ee_dpdd_AA_xy.ey
		src/d2_ee_dpdd_AA_xz.ey
		src/d2_ee_dpdd_AA_yx.ey
		src/d2_ee_dpdd_AA_yy.ey
		src/d2_ee_dpdd_AA_yz.ey
		src/d2_ee_dpdd_AA_zx.ey
		src/d2_ee_dpdd_AA_zy.ey
		src/d2_ee_dpdd_AA_zz.ey
		src/d2_ee_dpdd_AC_xx.ey
		src/d2_ee_dpdd_AC_xy.ey
		src/d2_ee_dpdd_AC_xz.ey
		src/d2_ee_dpdd_AC_yx.ey
		src/d2_ee_dpdd_AC_yy.ey
		src/d2_ee_dpdd_AC_yz.ey
		src/d2_ee_dpdd_AC_zx.ey
		src/d2_ee_dpdd_AC_zy.ey
		src/d2_ee_dpdd_AC_zz.ey
		src/d2_ee_dpdp_AC_xx.ey
		src/d2_ee_dpdp_AC_xy.ey
		src/d2_ee_dpdp_AC_xz.ey
		src/d2_ee_dpdp_AC_yx.ey
		src/d2_ee_dpdp_AC_yy.ey
		src/d2_ee_dpdp_AC_yz.ey
		src/d2_ee_dpdp_AC_zx.ey
		src/d2_ee_dpdp_AC_zy.ey
		src/d2_ee_dpdp_AC_zz.ey
		src/d2_ee_dppd_AA_xx.ey
		src/d2_ee_dppd_AA_xy.ey
		src/d2_ee_dppd_AA_xz.ey
		src/d2_ee_dppd_AA_yx.ey
		src/d2_ee_dppd_AA_yy.ey
		src/d2_ee_dppd_AA_yz.ey
		src/d2_ee_dppd_AA_zx.ey
		src/d2_ee_dppd_AA_zy.ey
		src/d2_ee_dppd_AA_zz.ey
		src/d2_ee_dsdd_AA_xx.ey
		src/d2_ee_dsdd_AA_xy.ey
		src/d2_ee_dsdd_AA_xz.ey
		src/d2_ee_dsdd_AA_yx.ey
		src/d2_ee_dsdd_AA_yy.ey
		src/d2_ee_dsdd_AA_yz.ey
		src/d2_ee_dsdd_AA_zx.ey
		src/d2_ee_dsdd_AA_zy.ey
		src/d2_ee_dsdd_AA_zz.ey
		src/d2_ee_dsdd_AC_xx.ey
		src/d2_ee_dsdd_AC_xy.ey
		src/d2_ee_dsdd_AC_xz.ey
		src/d2_ee_dsdd_AC_yx.ey
		src/d2_ee_dsdd_AC_yy.ey
		src/d2_ee_dsdd_AC_yz.ey
		src/d2_ee_dsdd_AC_zx.ey
		src/d2_ee_dsdd_AC_zy.ey
		src/d2_ee_dsdd_AC_zz.ey
		src/d2_ee_pddd_AA_xx.ey
		src/d2_ee_pddd_AA_xy.ey
		src/d2_ee_pddd_AA_xz.ey
		src/d2_ee_pddd_AA_yx.ey
		src/d2_ee_pddd_AA_yy.ey
		src/d2_ee_pddd_AA_yz.ey
		src/d2_ee_pddd_AA_zx.ey
		src/d2_ee_pddd_AA_zy.ey
		src/d2_ee_pddd_AA_zz.ey
		src/d2_ee_pddd_AB_xx.ey
		src/d2_ee_pddd_AB_xy.ey
		src/d2_ee_pddd_AB_xz.ey
		src/d2_ee_pddd_AB_yx.ey
		src/d2_ee_pddd_AB_yy.ey
		src/d2_ee_pddd_AB_yz.ey
		src/d2_ee_pddd_AB_zx.ey
		src/d2_ee_pddd_AB_zy.ey
		src/d2_ee_pddd_AB_zz.ey
		src/d2_ee_pddd_AC_xx.ey
		src/d2_ee_pddd_AC_xy.ey
		src/d2_ee_pddd_AC_xz.ey
		src/d2_ee_pddd_AC_yx.ey
		src/d2_ee_pddd_AC_yy.ey
		src/d2_ee_pddd_AC_yz.ey
		src/d2_ee_pddd_AC_zx.ey
		src/d2_ee_pddd_AC_zy.ey
		src/d2_ee_pddd_AC_zz.ey
		src/d2_ee_pddp_AC_xx.ey
		src/d2_ee_pddp_AC_xy.ey
		src/d2_ee_pddp_AC_xz.ey
		src/d2_ee_pddp_AC_yx.ey
		src/d2_ee_pddp_AC_yy.ey
		src/d2_ee_pddp_AC_yz.ey
		src/d2_ee_pddp_AC_zx.ey
		src/d2_ee_pddp_AC_zy.ey
		src/d2_ee_pddp_AC_zz.ey
		src/d2_ee_pdpd_AA_xx.ey
		src/d2_ee_pdpd_AA_xy.ey
		src/d2_ee_pdpd_AA_xz.ey
		src/d2_ee_pdpd_AA_yx.ey
		src/d2_ee_pdpd_AA_yy.ey
		src/d2_ee_pdpd_AA_yz.ey
		src/d2_ee_pdpd_AA_zx.ey
		src/d2_ee_pdpd_AA_zy.ey
		src/d2_ee_pdpd_AA_zz.ey
		src/d2_ee_pdpd_AB_xx.ey
		src/d2_ee_pdpd_AB_xy.ey
		src/d2_ee_pdpd_AB_xz.ey
		src/d2_ee_pdpd_AB_yx.ey
		src/d2_ee_pdpd_AB_yy.ey
		src/d2_ee_pdpd_AB_yz.ey
		src/d2_ee_pdpd_AB_zx.ey
		src/d2_ee_pdpd_AB_zy.ey
		src/d2_ee_pdpd_AB_zz.ey
		src/d2_ee_pdpd_AC_xx.ey
		src/d2_ee_pdpd_AC_xy.ey
		src/d2_ee_pdpd_AC_xz.ey
		src/d2_ee_pdpd_AC_yx.ey
		src/d2_ee_pdpd_AC_yy.ey
		src/d2_ee_pdpd_AC_yz.ey
		src/d2_ee_pdpd_AC_zx.ey
		src/d2_ee_pdpd_AC_zy.ey
		src/d2_ee_pdpd_AC_zz.ey
		src/d2_ee_ppdd_AA_xx.ey
		src/d2_ee_ppdd_AA_xy.ey
		src/d2_ee_ppdd_AA_xz.ey
		src/d2_ee_ppdd_AA_yx.ey
		src/d2_ee_ppdd_AA_yy.ey
		src/d2_ee_ppdd_AA_yz.ey
		src/d2_ee_ppdd_AA_zx.ey
		src/d2_ee_ppdd_AA_zy.ey
		src/d2_ee_ppdd_AA_zz.ey
		src/d2_ee_ppdd_AB_xx.ey
		src/d2_ee_ppdd_AB_xy.ey
		src/d2_ee_ppdd_AB_xz.ey
		src/d2_ee_ppdd_AB_yx.ey
		src/d2_ee_ppdd_AB_yy.ey
		src/d2_ee_ppdd_AB_yz.ey
		src/d2_ee_ppdd_AB_zx.ey
		src/d2_ee_ppdd_AB_zy.ey
		src/d2_ee_ppdd_AB_zz.ey
		src/d2_ee_ppdd_AC_xx.ey
		src/d2_ee_ppdd_AC_xy.ey
		src/d2_ee_ppdd_AC_xz.ey
		src/d2_ee_ppdd_AC_yx.ey
		src/d2_ee_ppdd_AC_yy.ey
		src/d2_ee_ppdd_AC_yz.ey
		src/d2_ee_ppdd_AC_zx.ey
		src/d2_ee_ppdd_AC_zy.ey
		src/d2_ee_ppdd_AC_zz.ey
		src/d2_ee_sddd_AA_xx.ey
		src/d2_ee_sddd_AA_xy.ey
		src/d2_ee_sddd_AA_xz.ey
		src/d2_ee_sddd_AA_yx.ey
		src/d2_ee_sddd_AA_yy.ey
		src/d2_ee_sddd_AA_yz.ey
		src/d2_ee_sddd_AA_zx.ey
		src/d2_ee_sddd_AA_zy.ey
		src/d2_ee_sddd_AA_zz.ey
		src/d2_ee_sddd_AB_xx.ey
		src/d2_ee_sddd_AB_xy.ey
		src/d2_ee_sddd_AB_xz.ey
		src/d2_ee_sddd_AB_yx.ey
		src/d2_ee_sddd_AB_yy.ey
		src/d2_ee_sddd_AB_yz.ey
		src/d2_ee_sddd_AB_zx.ey
		src/d2_ee_sddd_AB_zy.ey
		src/d2_ee_sddd_AB_zz.ey
		src/d2_ee_sddd_AC_xx.ey
		src/d2_ee_sddd_AC_xy.ey
		src/d2_ee_sddd_AC_xz.ey
		src/d2_ee_sddd_AC_yx.ey
		src/d2_ee_sddd_AC_yy.ey
		src/d2_ee_sddd_AC_yz.ey
		src/d2_ee_sddd_AC_zx.ey
		src/d2_ee_sddd_AC_zy.ey
		src/d2_ee_sddd_AC_zz.ey
        src/d2_ee_ddss_AA.ey
        src/d2_ee_ddss_AB.ey
	src/d2_ee_ddps_AA.ey
	src/d2_ee_ddps_AB.ey
        src/d2_ee_dpds_AC.ey
        src/d2_ee_dppp_AA.ey
        src/d2_ee_dpps_AA.ey
        src/d2_ee_dpsd_AA.ey
        src/d2_ee_dpss_AA.ey
        src/d2_ee_dsds_AC.ey
        src/d2_ee_dspd_AA.ey
        src/d2_ee_dspp_AA.ey
        src/d2_ee_dsps_AA.ey
        src/d2_ee_dssd_AA.ey
        src/d2_ee_dsss_AA.ey
        src/d2_ee_pdds_AC.ey
        src/d2_ee_pdpp_AA.ey
        src/d2_ee_pdpp_AB.ey
        src/d2_ee_pdps_AA.ey
        src/d2_ee_pdps_AB.ey
        src/d2_ee_pdsd_AA.ey
        src/d2_ee_pdsd_AB.ey
        src/d2_ee_pdsd_AC.ey
        src/d2_ee_pdsp_AC.ey
        src/d2_ee_pdss_AA.ey
        src/d2_ee_pdss_AB.ey
        src/d2_ee_pdss_AC.ey
        src/d2_ee_ppdp_AC.ey
        src/d2_ee_ppds_AC.ey
        src/d2_ee_pppd_AA.ey
        src/d2_ee_pppd_AB.ey
        src/d2_ee_pppd_AC.ey
        src/d2_ee_pppp_AA.ey
        src/d2_ee_pppp_AB.ey
        src/d2_ee_pppp_AC.ey
        src/d2_ee_ppps_AA.ey
        src/d2_ee_ppps_AB.ey
        src/d2_ee_ppps_AC.ey
        src/d2_ee_ppsd_AA.ey
        src/d2_ee_ppsd_AB.ey
        src/d2_ee_ppsd_AC.ey
        src/d2_ee_ppsp_AC.ey
        src/d2_ee_ppss_AA.ey
        src/d2_ee_ppss_AB.ey
        src/d2_ee_ppss_AC.ey
        src/d2_ee_psdd_AA.ey
        src/d2_ee_psdd_AB.ey
        src/d2_ee_psdd_AC.ey
        src/d2_ee_psdp_AC.ey
        src/d2_ee_psds_AC.ey
        src/d2_ee_pspd_AA.ey
        src/d2_ee_pspd_AB.ey
        src/d2_ee_pspd_AC.ey
        src/d2_ee_pspp_AA.ey
        src/d2_ee_pspp_AB.ey
        src/d2_ee_psps_AA.ey
        src/d2_ee_psps_AB.ey
        src/d2_ee_psps_AC.ey
        src/d2_ee_pssd_AA.ey
        src/d2_ee_pssd_AB.ey
        src/d2_ee_pssd_AC.ey
        src/d2_ee_pssp_AC.ey
        src/d2_ee_psss_AA.ey
        src/d2_ee_psss_AB.ey
        src/d2_ee_psss_AC.ey
        src/d2_ee_sddp_AC.ey
        src/d2_ee_sdds_AC.ey
        src/d2_ee_sdpd_AA.ey
        src/d2_ee_sdpd_AB.ey
        src/d2_ee_sdpp_AA.ey
        src/d2_ee_sdpp_AB.ey
        src/d2_ee_sdps_AA.ey
        src/d2_ee_sdps_AB.ey
        src/d2_ee_sdsd_AA.ey
        src/d2_ee_sdsd_AB.ey
        src/d2_ee_sdsd_AC.ey
        src/d2_ee_sdss_AA.ey
        src/d2_ee_sdss_AB.ey
        src/d2_ee_spdd_AA.ey
        src/d2_ee_spdd_AC.ey
        src/d2_ee_spdp_AC.ey
        src/d2_ee_spds_AC.ey
        src/d2_ee_sppd_AA.ey
        src/d2_ee_sppp_AA.ey
        src/d2_ee_spps_AA.ey
        src/d2_ee_spsd_AA.ey
        src/d2_ee_spsd_AC.ey
        src/d2_ee_spsp_AC.ey
        src/d2_ee_spss_AA.ey
        src/d2_ee_spss_AC.ey
        src/d2_ee_ssdd_AA.ey
        src/d2_ee_ssdd_AB.ey
        src/d2_ee_ssdd_AC.ey
        src/d2_ee_ssdp_AC.ey
        src/d2_ee_ssds_AC.ey
        src/d2_ee_sspd_AA.ey
        src/d2_ee_sspd_AB.ey
        src/d2_ee_sspp_AA.ey
        src/d2_ee_sspp_AB.ey
        src/d2_ee_ssps_AA.ey
        src/d2_ee_ssps_AB.ey
        src/d2_ee_sssd_AA.ey
        src/d2_ee_sssd_AB.ey
        src/d2_ee_sssd_AC.ey
        src/d2_ee_ssss_AA.ey
        src/d2_ee_ssss_AB.ey
        src/d2_ee_ssss_AC.ey
	src/d2_kinetic.ey
	src/d2_ne_dd_AA.ey
	src/d2_ne_dd_AB.ey
	src/d2_ne_dd_AC.ey
	src/d2_ne_dd_BB.ey
	src/d2_ne_dd_BC.ey
	src/d2_ne_dd_CC.ey
	src/d2_ne_dp_AA.ey
	src/d2_ne_dp_AB.ey
	src/d2_ne_dp_AC.ey
	src/d2_ne_dp_BB.ey
	src/d2_ne_dp_BC.ey
	src/d2_ne_dp_CC.ey
	src/d2_ne_ds_AA.ey
	src/d2_ne_ds_AB.ey
	src/d2_ne_ds_AC.ey
	src/d2_ne_ds_BB.ey
	src/d2_ne_ds_BC.ey
	src/d2_ne_ds_CC.ey
	src/d2_ne_pd_AA.ey
	src/d2_ne_pd_AB.ey
	src/d2_ne_pd_AC.ey
	src/d2_ne_pd_BB.ey
	src/d2_ne_pd_BC.ey
	src/d2_ne_pd_CC.ey
	src/d2_ne_pp_AA.ey
	src/d2_ne_pp_AB.ey
	src/d2_ne_pp_AC.ey
	src/d2_ne_pp_BB.ey
	src/d2_ne_pp_BC.ey
	src/d2_ne_pp_CC.ey
	src/d2_ne_ps_AA.ey
	src/d2_ne_ps_AB.ey
	src/d2_ne_ps_AC.ey
	src/d2_ne_ps_BB.ey
	src/d2_ne_ps_BC.ey
	src/d2_ne_ps_CC.ey
	src/d2_ne_sd_AA.ey
	src/d2_ne_sd_AB.ey
	src/d2_ne_sd_AC.ey
	src/d2_ne_sd_BB.ey
	src/d2_ne_sd_BC.ey
	src/d2_ne_sd_CC.ey
	src/d2_ne_sp_AA.ey
	src/d2_ne_sp_AB.ey
	src/d2_ne_sp_AC.ey
	src/d2_ne_sp_BB.ey
	src/d2_ne_sp_BC.ey
	src/d2_ne_sp_CC.ey
	src/d2_ne_ss_AA.ey
	src/d2_ne_ss_AB.ey
	src/d2_ne_ss_AC.ey
	src/d2_ne_ss_BB.ey
	src/d2_ne_ss_BC.ey
	src/d2_ne_ss_CC.ey
	src/d2_overlap.ey)

set ( HEADERS 
	d2_ee_matrix.hpp
	d2_kinetic_matrix.hpp
	d2_ne_matrix.hpp
	d2_overlap_matrix.hpp
	d2_ee_dddd_AA.hpp
d2_ee_dddd_AB.hpp
d2_ee_dddd_AC.hpp
d2_ee_dddd_AD.hpp
d2_ee_dddd_BB.hpp
d2_ee_dddd_BC.hpp
d2_ee_dddd_BD.hpp
d2_ee_dddd_CC.hpp
d2_ee_dddd_CD.hpp
d2_ee_dddd_DD.hpp
d2_ee_dddp_AA.hpp
d2_ee_dddp_AB.hpp
d2_ee_dddp_AC.hpp
d2_ee_dddp_AD.hpp
d2_ee_dddp_BB.hpp
d2_ee_dddp_BC.hpp
d2_ee_dddp_BD.hpp
d2_ee_dddp_CC.hpp
d2_ee_dddp_CD.hpp
d2_ee_dddp_DD.hpp
d2_ee_ddds_AA.hpp
d2_ee_ddds_AB.hpp
d2_ee_ddds_AC.hpp
d2_ee_ddds_AD.hpp
d2_ee_ddds_BB.hpp
d2_ee_ddds_BC.hpp
d2_ee_ddds_BD.hpp
d2_ee_ddds_CC.hpp
d2_ee_ddds_CD.hpp
d2_ee_ddds_DD.hpp
d2_ee_ddpd_AA.hpp
d2_ee_ddpd_AB.hpp
d2_ee_ddpd_AC.hpp
d2_ee_ddpd_AD.hpp
d2_ee_ddpd_BB.hpp
d2_ee_ddpd_BC.hpp
d2_ee_ddpd_BD.hpp
d2_ee_ddpd_CC.hpp
d2_ee_ddpd_CD.hpp
d2_ee_ddpd_DD.hpp
d2_ee_ddpp_AA.hpp
d2_ee_ddpp_AB.hpp
d2_ee_ddpp_AC.hpp
d2_ee_ddpp_AD.hpp
d2_ee_ddpp_BB.hpp
d2_ee_ddpp_BC.hpp
d2_ee_ddpp_BD.hpp
d2_ee_ddpp_CC.hpp
d2_ee_ddpp_CD.hpp
d2_ee_ddpp_DD.hpp
d2_ee_ddps_AA.hpp
d2_ee_ddps_AB.hpp
d2_ee_ddps_AC.hpp
d2_ee_ddps_AD.hpp
d2_ee_ddps_BB.hpp
d2_ee_ddps_BC.hpp
d2_ee_ddps_BD.hpp
d2_ee_ddps_CC.hpp
d2_ee_ddps_CD.hpp
d2_ee_ddps_DD.hpp
d2_ee_ddsd_AA.hpp
d2_ee_ddsd_AB.hpp
d2_ee_ddsd_AC.hpp
d2_ee_ddsd_AD.hpp
d2_ee_ddsd_BB.hpp
d2_ee_ddsd_BC.hpp
d2_ee_ddsd_BD.hpp
d2_ee_ddsd_CC.hpp
d2_ee_ddsd_CD.hpp
d2_ee_ddsd_DD.hpp
d2_ee_ddsp_AA.hpp
d2_ee_ddsp_AB.hpp
d2_ee_ddsp_AC.hpp
d2_ee_ddsp_AD.hpp
d2_ee_ddsp_BB.hpp
d2_ee_ddsp_BC.hpp
d2_ee_ddsp_BD.hpp
d2_ee_ddsp_CC.hpp
d2_ee_ddsp_CD.hpp
d2_ee_ddsp_DD.hpp
d2_ee_ddss_AA.hpp
d2_ee_ddss_AB.hpp
d2_ee_ddss_AC.hpp
d2_ee_ddss_AD.hpp
d2_ee_ddss_BB.hpp
d2_ee_ddss_BC.hpp
d2_ee_ddss_BD.hpp
d2_ee_ddss_CC.hpp
d2_ee_ddss_CD.hpp
d2_ee_ddss_DD.hpp
d2_ee_dpdd_AA.hpp
d2_ee_dpdd_AB.hpp
d2_ee_dpdd_AC.hpp
d2_ee_dpdd_AD.hpp
d2_ee_dpdd_BB.hpp
d2_ee_dpdd_BC.hpp
d2_ee_dpdd_BD.hpp
d2_ee_dpdd_CC.hpp
d2_ee_dpdd_CD.hpp
d2_ee_dpdd_DD.hpp
d2_ee_dpdp_AA.hpp
d2_ee_dpdp_AB.hpp
d2_ee_dpdp_AC.hpp
d2_ee_dpdp_AD.hpp
d2_ee_dpdp_BB.hpp
d2_ee_dpdp_BC.hpp
d2_ee_dpdp_BD.hpp
d2_ee_dpdp_CC.hpp
d2_ee_dpdp_CD.hpp
d2_ee_dpdp_DD.hpp
d2_ee_dpds_AA.hpp
d2_ee_dpds_AB.hpp
d2_ee_dpds_AC.hpp
d2_ee_dpds_AD.hpp
d2_ee_dpds_BB.hpp
d2_ee_dpds_BC.hpp
d2_ee_dpds_BD.hpp
d2_ee_dpds_CC.hpp
d2_ee_dpds_CD.hpp
d2_ee_dpds_DD.hpp
d2_ee_dppd_AA.hpp
d2_ee_dppd_AB.hpp
d2_ee_dppd_AC.hpp
d2_ee_dppd_AD.hpp
d2_ee_dppd_BB.hpp
d2_ee_dppd_BC.hpp
d2_ee_dppd_BD.hpp
d2_ee_dppd_CC.hpp
d2_ee_dppd_CD.hpp
d2_ee_dppd_DD.hpp
d2_ee_dppp_AA.hpp
d2_ee_dppp_AB.hpp
d2_ee_dppp_AC.hpp
d2_ee_dppp_AD.hpp
d2_ee_dppp_BB.hpp
d2_ee_dppp_BC.hpp
d2_ee_dppp_BD.hpp
d2_ee_dppp_CC.hpp
d2_ee_dppp_CD.hpp
d2_ee_dppp_DD.hpp
d2_ee_dpps_AA.hpp
d2_ee_dpps_AB.hpp
d2_ee_dpps_AC.hpp
d2_ee_dpps_AD.hpp
d2_ee_dpps_BB.hpp
d2_ee_dpps_BC.hpp
d2_ee_dpps_BD.hpp
d2_ee_dpps_CC.hpp
d2_ee_dpps_CD.hpp
d2_ee_dpps_DD.hpp
d2_ee_dpsd_AA.hpp
d2_ee_dpsd_AB.hpp
d2_ee_dpsd_AC.hpp
d2_ee_dpsd_AD.hpp
d2_ee_dpsd_BB.hpp
d2_ee_dpsd_BC.hpp
d2_ee_dpsd_BD.hpp
d2_ee_dpsd_CC.hpp
d2_ee_dpsd_CD.hpp
d2_ee_dpsd_DD.hpp
d2_ee_dpsp_AA.hpp
d2_ee_dpsp_AB.hpp
d2_ee_dpsp_AC.hpp
d2_ee_dpsp_AD.hpp
d2_ee_dpsp_BB.hpp
d2_ee_dpsp_BC.hpp
d2_ee_dpsp_BD.hpp
d2_ee_dpsp_CC.hpp
d2_ee_dpsp_CD.hpp
d2_ee_dpsp_DD.hpp
d2_ee_dpss_AA.hpp
d2_ee_dpss_AB.hpp
d2_ee_dpss_AC.hpp
d2_ee_dpss_AD.hpp
d2_ee_dpss_BB.hpp
d2_ee_dpss_BC.hpp
d2_ee_dpss_BD.hpp
d2_ee_dpss_CC.hpp
d2_ee_dpss_CD.hpp
d2_ee_dpss_DD.hpp
d2_ee_dsdd_AA.hpp
d2_ee_dsdd_AB.hpp
d2_ee_dsdd_AC.hpp
d2_ee_dsdd_AD.hpp
d2_ee_dsdd_BB.hpp
d2_ee_dsdd_BC.hpp
d2_ee_dsdd_BD.hpp
d2_ee_dsdd_CC.hpp
d2_ee_dsdd_CD.hpp
d2_ee_dsdd_DD.hpp
d2_ee_dsdp_AA.hpp
d2_ee_dsdp_AB.hpp
d2_ee_dsdp_AC.hpp
d2_ee_dsdp_AD.hpp
d2_ee_dsdp_BB.hpp
d2_ee_dsdp_BC.hpp
d2_ee_dsdp_BD.hpp
d2_ee_dsdp_CC.hpp
d2_ee_dsdp_CD.hpp
d2_ee_dsdp_DD.hpp
d2_ee_dsds_AA.hpp
d2_ee_dsds_AB.hpp
d2_ee_dsds_AC.hpp
d2_ee_dsds_AD.hpp
d2_ee_dsds_BB.hpp
d2_ee_dsds_BC.hpp
d2_ee_dsds_BD.hpp
d2_ee_dsds_CC.hpp
d2_ee_dsds_CD.hpp
d2_ee_dsds_DD.hpp
d2_ee_dspd_AA.hpp
d2_ee_dspd_AB.hpp
d2_ee_dspd_AC.hpp
d2_ee_dspd_AD.hpp
d2_ee_dspd_BB.hpp
d2_ee_dspd_BC.hpp
d2_ee_dspd_BD.hpp
d2_ee_dspd_CC.hpp
d2_ee_dspd_CD.hpp
d2_ee_dspd_DD.hpp
d2_ee_dspp_AA.hpp
d2_ee_dspp_AB.hpp
d2_ee_dspp_AC.hpp
d2_ee_dspp_AD.hpp
d2_ee_dspp_BB.hpp
d2_ee_dspp_BC.hpp
d2_ee_dspp_BD.hpp
d2_ee_dspp_CC.hpp
d2_ee_dspp_CD.hpp
d2_ee_dspp_DD.hpp
d2_ee_dsps_AA.hpp
d2_ee_dsps_AB.hpp
d2_ee_dsps_AC.hpp
d2_ee_dsps_AD.hpp
d2_ee_dsps_BB.hpp
d2_ee_dsps_BC.hpp
d2_ee_dsps_BD.hpp
d2_ee_dsps_CC.hpp
d2_ee_dsps_CD.hpp
d2_ee_dsps_DD.hpp
d2_ee_dssd_AA.hpp
d2_ee_dssd_AB.hpp
d2_ee_dssd_AC.hpp
d2_ee_dssd_AD.hpp
d2_ee_dssd_BB.hpp
d2_ee_dssd_BC.hpp
d2_ee_dssd_BD.hpp
d2_ee_dssd_CC.hpp
d2_ee_dssd_CD.hpp
d2_ee_dssd_DD.hpp
d2_ee_dssp_AA.hpp
d2_ee_dssp_AB.hpp
d2_ee_dssp_AC.hpp
d2_ee_dssp_AD.hpp
d2_ee_dssp_BB.hpp
d2_ee_dssp_BC.hpp
d2_ee_dssp_BD.hpp
d2_ee_dssp_CC.hpp
d2_ee_dssp_CD.hpp
d2_ee_dssp_DD.hpp
d2_ee_dsss_AA.hpp
d2_ee_dsss_AB.hpp
d2_ee_dsss_AC.hpp
d2_ee_dsss_AD.hpp
d2_ee_dsss_BB.hpp
d2_ee_dsss_BC.hpp
d2_ee_dsss_BD.hpp
d2_ee_dsss_CC.hpp
d2_ee_dsss_CD.hpp
d2_ee_dsss_DD.hpp
d2_ee_pddd_AA.hpp
d2_ee_pddd_AB.hpp
d2_ee_pddd_AC.hpp
d2_ee_pddd_AD.hpp
d2_ee_pddd_BB.hpp
d2_ee_pddd_BC.hpp
d2_ee_pddd_BD.hpp
d2_ee_pddd_CC.hpp
d2_ee_pddd_CD.hpp
d2_ee_pddd_DD.hpp
d2_ee_pddp_AA.hpp
d2_ee_pddp_AB.hpp
d2_ee_pddp_AC.hpp
d2_ee_pddp_AD.hpp
d2_ee_pddp_BB.hpp
d2_ee_pddp_BC.hpp
d2_ee_pddp_BD.hpp
d2_ee_pddp_CC.hpp
d2_ee_pddp_CD.hpp
d2_ee_pddp_DD.hpp
d2_ee_pdds_AA.hpp
d2_ee_pdds_AB.hpp
d2_ee_pdds_AC.hpp
d2_ee_pdds_AD.hpp
d2_ee_pdds_BB.hpp
d2_ee_pdds_BC.hpp
d2_ee_pdds_BD.hpp
d2_ee_pdds_CC.hpp
d2_ee_pdds_CD.hpp
d2_ee_pdds_DD.hpp
d2_ee_pdpd_AA.hpp
d2_ee_pdpd_AB.hpp
d2_ee_pdpd_AC.hpp
d2_ee_pdpd_AD.hpp
d2_ee_pdpd_BB.hpp
d2_ee_pdpd_BC.hpp
d2_ee_pdpd_BD.hpp
d2_ee_pdpd_CC.hpp
d2_ee_pdpd_CD.hpp
d2_ee_pdpd_DD.hpp
d2_ee_pdpp_AA.hpp
d2_ee_pdpp_AB.hpp
d2_ee_pdpp_AC.hpp
d2_ee_pdpp_AD.hpp
d2_ee_pdpp_BB.hpp
d2_ee_pdpp_BC.hpp
d2_ee_pdpp_BD.hpp
d2_ee_pdpp_CC.hpp
d2_ee_pdpp_CD.hpp
d2_ee_pdpp_DD.hpp
d2_ee_pdps_AA.hpp
d2_ee_pdps_AB.hpp
d2_ee_pdps_AC.hpp
d2_ee_pdps_AD.hpp
d2_ee_pdps_BB.hpp
d2_ee_pdps_BC.hpp
d2_ee_pdps_BD.hpp
d2_ee_pdps_CC.hpp
d2_ee_pdps_CD.hpp
d2_ee_pdps_DD.hpp
d2_ee_pdsd_AA.hpp
d2_ee_pdsd_AB.hpp
d2_ee_pdsd_AC.hpp
d2_ee_pdsd_AD.hpp
d2_ee_pdsd_BB.hpp
d2_ee_pdsd_BC.hpp
d2_ee_pdsd_BD.hpp
d2_ee_pdsd_CC.hpp
d2_ee_pdsd_CD.hpp
d2_ee_pdsd_DD.hpp
d2_ee_pdsp_AA.hpp
d2_ee_pdsp_AB.hpp
d2_ee_pdsp_AC.hpp
d2_ee_pdsp_AD.hpp
d2_ee_pdsp_BB.hpp
d2_ee_pdsp_BC.hpp
d2_ee_pdsp_BD.hpp
d2_ee_pdsp_CC.hpp
d2_ee_pdsp_CD.hpp
d2_ee_pdsp_DD.hpp
d2_ee_pdss_AA.hpp
d2_ee_pdss_AB.hpp
d2_ee_pdss_AC.hpp
d2_ee_pdss_AD.hpp
d2_ee_pdss_BB.hpp
d2_ee_pdss_BC.hpp
d2_ee_pdss_BD.hpp
d2_ee_pdss_CC.hpp
d2_ee_pdss_CD.hpp
d2_ee_pdss_DD.hpp
d2_ee_ppdd_AA.hpp
d2_ee_ppdd_AB.hpp
d2_ee_ppdd_AC.hpp
d2_ee_dddd_AA_xx.hpp
d2_ee_dddd_AA_xy.hpp
d2_ee_dddd_AA_xz.hpp
d2_ee_dddd_AA_yx.hpp
d2_ee_dddd_AA_yy.hpp
d2_ee_dddd_AA_yz.hpp
d2_ee_dddd_AA_zx.hpp
d2_ee_dddd_AA_zy.hpp
d2_ee_dddd_AA_zz.hpp
d2_ee_dddd_AB_xx.hpp
d2_ee_dddd_AB_xy.hpp
d2_ee_dddd_AB_xz.hpp
d2_ee_dddd_AB_yx.hpp
d2_ee_dddd_AB_yy.hpp
d2_ee_dddd_AB_yz.hpp
d2_ee_dddd_AB_zx.hpp
d2_ee_dddd_AB_zy.hpp
d2_ee_dddd_AB_zz.hpp
d2_ee_dddd_AC_xx.hpp
d2_ee_dddd_AC_xy.hpp
d2_ee_dddd_AC_xz.hpp
d2_ee_dddd_AC_yx.hpp
d2_ee_dddd_AC_yy.hpp
d2_ee_dddd_AC_yz.hpp
d2_ee_dddd_AC_zx.hpp
d2_ee_dddd_AC_zy.hpp
d2_ee_dddd_AC_zz.hpp
d2_ee_ddpd_AA_xx.hpp
d2_ee_ddpd_AA_xy.hpp
d2_ee_ddpd_AA_xz.hpp
d2_ee_ddpd_AA_yx.hpp
d2_ee_ddpd_AA_yy.hpp
d2_ee_ddpd_AA_yz.hpp
d2_ee_ddpd_AA_zx.hpp
d2_ee_ddpd_AA_zy.hpp
d2_ee_ddpd_AA_zz.hpp
d2_ee_ddpd_AB_xx.hpp
d2_ee_ddpd_AB_xy.hpp
d2_ee_ddpd_AB_xz.hpp
d2_ee_ddpd_AB_yx.hpp
d2_ee_ddpd_AB_yy.hpp
d2_ee_ddpd_AB_yz.hpp
d2_ee_ddpd_AB_zx.hpp
d2_ee_ddpd_AB_zy.hpp
d2_ee_ddpd_AB_zz.hpp
d2_ee_ddpp_AA_xx.hpp
d2_ee_ddpp_AA_xy.hpp
d2_ee_ddpp_AA_xz.hpp
d2_ee_ddpp_AA_yx.hpp
d2_ee_ddpp_AA_yy.hpp
d2_ee_ddpp_AA_yz.hpp
d2_ee_ddpp_AA_zx.hpp
d2_ee_ddpp_AA_zy.hpp
d2_ee_ddpp_AA_zz.hpp
d2_ee_ddpp_AB_xx.hpp
d2_ee_ddpp_AB_xy.hpp
d2_ee_ddpp_AB_xz.hpp
d2_ee_ddpp_AB_yx.hpp
d2_ee_ddpp_AB_yy.hpp
d2_ee_ddpp_AB_yz.hpp
d2_ee_ddpp_AB_zx.hpp
d2_ee_ddpp_AB_zy.hpp
d2_ee_ddpp_AB_zz.hpp
d2_ee_ddsd_AA_xx.hpp
d2_ee_ddsd_AA_xy.hpp
d2_ee_ddsd_AA_xz.hpp
d2_ee_ddsd_AA_yx.hpp
d2_ee_ddsd_AA_yy.hpp
d2_ee_ddsd_AA_yz.hpp
d2_ee_ddsd_AA_zx.hpp
d2_ee_ddsd_AA_zy.hpp
d2_ee_ddsd_AA_zz.hpp
d2_ee_ddsd_AB_xx.hpp
d2_ee_ddsd_AB_xy.hpp
d2_ee_ddsd_AB_xz.hpp
d2_ee_ddsd_AB_yx.hpp
d2_ee_ddsd_AB_yy.hpp
d2_ee_ddsd_AB_yz.hpp
d2_ee_ddsd_AB_zx.hpp
d2_ee_ddsd_AB_zy.hpp
d2_ee_ddsd_AB_zz.hpp
d2_ee_dpdd_AA_xx.hpp
d2_ee_dpdd_AA_xy.hpp
d2_ee_dpdd_AA_xz.hpp
d2_ee_dpdd_AA_yx.hpp
d2_ee_dpdd_AA_yy.hpp
d2_ee_dpdd_AA_yz.hpp
d2_ee_dpdd_AA_zx.hpp
d2_ee_dpdd_AA_zy.hpp
d2_ee_dpdd_AA_zz.hpp
d2_ee_dpdd_AC_xx.hpp
d2_ee_dpdd_AC_xy.hpp
d2_ee_dpdd_AC_xz.hpp
d2_ee_dpdd_AC_yx.hpp
d2_ee_dpdd_AC_yy.hpp
d2_ee_dpdd_AC_yz.hpp
d2_ee_dpdd_AC_zx.hpp
d2_ee_dpdd_AC_zy.hpp
d2_ee_dpdd_AC_zz.hpp
d2_ee_dpdp_AC_xx.hpp
d2_ee_dpdp_AC_xy.hpp
d2_ee_dpdp_AC_xz.hpp
d2_ee_dpdp_AC_yx.hpp
d2_ee_dpdp_AC_yy.hpp
d2_ee_dpdp_AC_yz.hpp
d2_ee_dpdp_AC_zx.hpp
d2_ee_dpdp_AC_zy.hpp
d2_ee_dpdp_AC_zz.hpp
d2_ee_dppd_AA_xx.hpp
d2_ee_dppd_AA_xy.hpp
d2_ee_dppd_AA_xz.hpp
d2_ee_dppd_AA_yx.hpp
d2_ee_dppd_AA_yy.hpp
d2_ee_dppd_AA_yz.hpp
d2_ee_dppd_AA_zx.hpp
d2_ee_dppd_AA_zy.hpp
d2_ee_dppd_AA_zz.hpp
d2_ee_dsdd_AA_xx.hpp
d2_ee_dsdd_AA_xy.hpp
d2_ee_dsdd_AA_xz.hpp
d2_ee_dsdd_AA_yx.hpp
d2_ee_dsdd_AA_yy.hpp
d2_ee_dsdd_AA_yz.hpp
d2_ee_dsdd_AA_zx.hpp
d2_ee_dsdd_AA_zy.hpp
d2_ee_dsdd_AA_zz.hpp
d2_ee_dsdd_AC_xx.hpp
d2_ee_dsdd_AC_xy.hpp
d2_ee_dsdd_AC_xz.hpp
d2_ee_dsdd_AC_yx.hpp
d2_ee_dsdd_AC_yy.hpp
d2_ee_dsdd_AC_yz.hpp
d2_ee_dsdd_AC_zx.hpp
d2_ee_dsdd_AC_zy.hpp
d2_ee_dsdd_AC_zz.hpp
d2_ee_pddd_AA_xx.hpp
d2_ee_pddd_AA_xy.hpp
d2_ee_pddd_AA_xz.hpp
d2_ee_pddd_AA_yx.hpp
d2_ee_pddd_AA_yy.hpp
d2_ee_pddd_AA_yz.hpp
d2_ee_pddd_AA_zx.hpp
d2_ee_pddd_AA_zy.hpp
d2_ee_pddd_AA_zz.hpp
d2_ee_pddd_AB_xx.hpp
d2_ee_pddd_AB_xy.hpp
d2_ee_pddd_AB_xz.hpp
d2_ee_pddd_AB_yx.hpp
d2_ee_pddd_AB_yy.hpp
d2_ee_pddd_AB_yz.hpp
d2_ee_pddd_AB_zx.hpp
d2_ee_pddd_AB_zy.hpp
d2_ee_pddd_AB_zz.hpp
d2_ee_pddd_AC_xx.hpp
d2_ee_pddd_AC_xy.hpp
d2_ee_pddd_AC_xz.hpp
d2_ee_pddd_AC_yx.hpp
d2_ee_pddd_AC_yy.hpp
d2_ee_pddd_AC_yz.hpp
d2_ee_pddd_AC_zx.hpp
d2_ee_pddd_AC_zy.hpp
d2_ee_pddd_AC_zz.hpp
d2_ee_pddp_AC_xx.hpp
d2_ee_pddp_AC_xy.hpp
d2_ee_pddp_AC_xz.hpp
d2_ee_pddp_AC_yx.hpp
d2_ee_pddp_AC_yy.hpp
d2_ee_pddp_AC_yz.hpp
d2_ee_pddp_AC_zx.hpp
d2_ee_pddp_AC_zy.hpp
d2_ee_pddp_AC_zz.hpp
d2_ee_pdpd_AA_xx.hpp
d2_ee_pdpd_AA_xy.hpp
d2_ee_pdpd_AA_xz.hpp
d2_ee_pdpd_AA_yx.hpp
d2_ee_pdpd_AA_yy.hpp
d2_ee_pdpd_AA_yz.hpp
d2_ee_pdpd_AA_zx.hpp
d2_ee_pdpd_AA_zy.hpp
d2_ee_pdpd_AA_zz.hpp
d2_ee_pdpd_AB_xx.hpp
d2_ee_pdpd_AB_xy.hpp
d2_ee_pdpd_AB_xz.hpp
d2_ee_pdpd_AB_yx.hpp
d2_ee_pdpd_AB_yy.hpp
d2_ee_pdpd_AB_yz.hpp
d2_ee_pdpd_AB_zx.hpp
d2_ee_pdpd_AB_zy.hpp
d2_ee_pdpd_AB_zz.hpp
d2_ee_pdpd_AC_xx.hpp
d2_ee_pdpd_AC_xy.hpp
d2_ee_pdpd_AC_xz.hpp
d2_ee_pdpd_AC_yx.hpp
d2_ee_pdpd_AC_yy.hpp
d2_ee_pdpd_AC_yz.hpp
d2_ee_pdpd_AC_zx.hpp
d2_ee_pdpd_AC_zy.hpp
d2_ee_pdpd_AC_zz.hpp
d2_ee_ppdd_AA_xx.hpp
d2_ee_ppdd_AA_xy.hpp
d2_ee_ppdd_AA_xz.hpp
d2_ee_ppdd_AA_yx.hpp
d2_ee_ppdd_AA_yy.hpp
d2_ee_ppdd_AA_yz.hpp
d2_ee_ppdd_AA_zx.hpp
d2_ee_ppdd_AA_zy.hpp
d2_ee_ppdd_AA_zz.hpp
d2_ee_ppdd_AB_xx.hpp
d2_ee_ppdd_AB_xy.hpp
d2_ee_ppdd_AB_xz.hpp
d2_ee_ppdd_AB_yx.hpp
d2_ee_ppdd_AB_yy.hpp
d2_ee_ppdd_AB_yz.hpp
d2_ee_ppdd_AB_zx.hpp
d2_ee_ppdd_AB_zy.hpp
d2_ee_ppdd_AB_zz.hpp
d2_ee_ppdd_AC_xx.hpp
d2_ee_ppdd_AC_xy.hpp
d2_ee_ppdd_AC_xz.hpp
d2_ee_ppdd_AC_yx.hpp
d2_ee_ppdd_AC_yy.hpp
d2_ee_ppdd_AC_yz.hpp
d2_ee_ppdd_AC_zx.hpp
d2_ee_ppdd_AC_zy.hpp
d2_ee_ppdd_AC_zz.hpp
d2_ee_sddd_AA_xx.hpp
d2_ee_sddd_AA_xy.hpp
d2_ee_sddd_AA_xz.hpp
d2_ee_sddd_AA_yx.hpp
d2_ee_sddd_AA_yy.hpp
d2_ee_sddd_AA_yz.hpp
d2_ee_sddd_AA_zx.hpp
d2_ee_sddd_AA_zy.hpp
d2_ee_sddd_AA_zz.hpp
d2_ee_sddd_AB_xx.hpp
d2_ee_sddd_AB_xy.hpp
d2_ee_sddd_AB_xz.hpp
d2_ee_sddd_AB_yx.hpp
d2_ee_sddd_AB_yy.hpp
d2_ee_sddd_AB_yz.hpp
d2_ee_sddd_AB_zx.hpp
d2_ee_sddd_AB_zy.hpp
d2_ee_sddd_AB_zz.hpp
d2_ee_sddd_AC_xx.hpp
d2_ee_sddd_AC_xy.hpp
d2_ee_sddd_AC_xz.hpp
d2_ee_sddd_AC_yx.hpp
d2_ee_sddd_AC_yy.hpp
d2_ee_sddd_AC_yz.hpp
d2_ee_sddd_AC_zx.hpp
d2_ee_sddd_AC_zy.hpp
d2_ee_sddd_AC_zz.hpp
d2_ee_ppdd_AD.hpp
d2_ee_ppdd_BB.hpp
d2_ee_ppdd_BC.hpp
d2_ee_ppdd_BD.hpp
d2_ee_ppdd_CC.hpp
d2_ee_ppdd_CD.hpp
d2_ee_ppdd_DD.hpp
d2_ee_ppdp_AA.hpp
d2_ee_ppdp_AB.hpp
d2_ee_ppdp_AC.hpp
d2_ee_ppdp_AD.hpp
d2_ee_ppdp_BB.hpp
d2_ee_ppdp_BC.hpp
d2_ee_ppdp_BD.hpp
d2_ee_ppdp_CC.hpp
d2_ee_ppdp_CD.hpp
d2_ee_ppdp_DD.hpp
d2_ee_ppds_AA.hpp
d2_ee_ppds_AB.hpp
d2_ee_ppds_AC.hpp
d2_ee_ppds_AD.hpp
d2_ee_ppds_BB.hpp
d2_ee_ppds_BC.hpp
d2_ee_ppds_BD.hpp
d2_ee_ppds_CC.hpp
d2_ee_ppds_CD.hpp
d2_ee_ppds_DD.hpp
d2_ee_pppd_AA.hpp
d2_ee_pppd_AB.hpp
d2_ee_pppd_AC.hpp
d2_ee_pppd_AD.hpp
d2_ee_pppd_BB.hpp
d2_ee_pppd_BC.hpp
d2_ee_pppd_BD.hpp
d2_ee_pppd_CC.hpp
d2_ee_pppd_CD.hpp
d2_ee_pppd_DD.hpp
d2_ee_pppp_AA.hpp
d2_ee_pppp_AB.hpp
d2_ee_pppp_AC.hpp
d2_ee_pppp_AD.hpp
d2_ee_pppp_BB.hpp
d2_ee_pppp_BC.hpp
d2_ee_pppp_BD.hpp
d2_ee_pppp_CC.hpp
d2_ee_pppp_CD.hpp
d2_ee_pppp_DD.hpp
d2_ee_ppps_AA.hpp
d2_ee_ppps_AB.hpp
d2_ee_ppps_AC.hpp
d2_ee_ppps_AD.hpp
d2_ee_ppps_BB.hpp
d2_ee_ppps_BC.hpp
d2_ee_ppps_BD.hpp
d2_ee_ppps_CC.hpp
d2_ee_ppps_CD.hpp
d2_ee_ppps_DD.hpp
d2_ee_ppsd_AA.hpp
d2_ee_ppsd_AB.hpp
d2_ee_ppsd_AC.hpp
d2_ee_ppsd_AD.hpp
d2_ee_ppsd_BB.hpp
d2_ee_ppsd_BC.hpp
d2_ee_ppsd_BD.hpp
d2_ee_ppsd_CC.hpp
d2_ee_ppsd_CD.hpp
d2_ee_ppsd_DD.hpp
d2_ee_ppsp_AA.hpp
d2_ee_ppsp_AB.hpp
d2_ee_ppsp_AC.hpp
d2_ee_ppsp_AD.hpp
d2_ee_ppsp_BB.hpp
d2_ee_ppsp_BC.hpp
d2_ee_ppsp_BD.hpp
d2_ee_ppsp_CC.hpp
d2_ee_ppsp_CD.hpp
d2_ee_ppsp_DD.hpp
d2_ee_ppss_AA.hpp
d2_ee_ppss_AB.hpp
d2_ee_ppss_AC.hpp
d2_ee_ppss_AD.hpp
d2_ee_ppss_BB.hpp
d2_ee_ppss_BC.hpp
d2_ee_ppss_BD.hpp
d2_ee_ppss_CC.hpp
d2_ee_ppss_CD.hpp
d2_ee_ppss_DD.hpp
d2_ee_psdd_AA.hpp
d2_ee_psdd_AB.hpp
d2_ee_psdd_AC.hpp
d2_ee_psdd_AD.hpp
d2_ee_psdd_BB.hpp
d2_ee_psdd_BC.hpp
d2_ee_psdd_BD.hpp
d2_ee_psdd_CC.hpp
d2_ee_psdd_CD.hpp
d2_ee_psdd_DD.hpp
d2_ee_psdp_AA.hpp
d2_ee_psdp_AB.hpp
d2_ee_psdp_AC.hpp
d2_ee_psdp_AD.hpp
d2_ee_psdp_BB.hpp
d2_ee_psdp_BC.hpp
d2_ee_psdp_BD.hpp
d2_ee_psdp_CC.hpp
d2_ee_psdp_CD.hpp
d2_ee_psdp_DD.hpp
d2_ee_psds_AA.hpp
d2_ee_psds_AB.hpp
d2_ee_psds_AC.hpp
d2_ee_psds_AD.hpp
d2_ee_psds_BB.hpp
d2_ee_psds_BC.hpp
d2_ee_psds_BD.hpp
d2_ee_psds_CC.hpp
d2_ee_psds_CD.hpp
d2_ee_psds_DD.hpp
d2_ee_pspd_AA.hpp
d2_ee_pspd_AB.hpp
d2_ee_pspd_AC.hpp
d2_ee_pspd_AD.hpp
d2_ee_pspd_BB.hpp
d2_ee_pspd_BC.hpp
d2_ee_pspd_BD.hpp
d2_ee_pspd_CC.hpp
d2_ee_pspd_CD.hpp
d2_ee_pspd_DD.hpp
d2_ee_pspp_AA.hpp
d2_ee_pspp_AB.hpp
d2_ee_pspp_AC.hpp
d2_ee_pspp_AD.hpp
d2_ee_pspp_BB.hpp
d2_ee_pspp_BC.hpp
d2_ee_pspp_BD.hpp
d2_ee_pspp_CC.hpp
d2_ee_pspp_CD.hpp
d2_ee_pspp_DD.hpp
d2_ee_psps_AA.hpp
d2_ee_psps_AB.hpp
d2_ee_psps_AC.hpp
d2_ee_psps_AD.hpp
d2_ee_psps_BB.hpp
d2_ee_psps_BC.hpp
d2_ee_psps_BD.hpp
d2_ee_psps_CC.hpp
d2_ee_psps_CD.hpp
d2_ee_psps_DD.hpp
d2_ee_pssd_AA.hpp
d2_ee_pssd_AB.hpp
d2_ee_pssd_AC.hpp
d2_ee_pssd_AD.hpp
d2_ee_pssd_BB.hpp
d2_ee_pssd_BC.hpp
d2_ee_pssd_BD.hpp
d2_ee_pssd_CC.hpp
d2_ee_pssd_CD.hpp
d2_ee_pssd_DD.hpp
d2_ee_pssp_AA.hpp
d2_ee_pssp_AB.hpp
d2_ee_pssp_AC.hpp
d2_ee_pssp_AD.hpp
d2_ee_pssp_BB.hpp
d2_ee_pssp_BC.hpp
d2_ee_pssp_BD.hpp
d2_ee_pssp_CC.hpp
d2_ee_pssp_CD.hpp
d2_ee_pssp_DD.hpp
d2_ee_psss_AA.hpp
d2_ee_psss_AB.hpp
d2_ee_psss_AC.hpp
d2_ee_psss_AD.hpp
d2_ee_psss_BB.hpp
d2_ee_psss_BC.hpp
d2_ee_psss_BD.hpp
d2_ee_psss_CC.hpp
d2_ee_psss_CD.hpp
d2_ee_psss_DD.hpp
d2_ee_sddd_AA.hpp
d2_ee_sddd_AB.hpp
d2_ee_sddd_AC.hpp
d2_ee_sddd_AD.hpp
d2_ee_sddd_BB.hpp
d2_ee_sddd_BC.hpp
d2_ee_sddd_BD.hpp
d2_ee_sddd_CC.hpp
d2_ee_sddd_CD.hpp
d2_ee_sddd_DD.hpp
d2_ee_sddp_AA.hpp
d2_ee_sddp_AB.hpp
d2_ee_sddp_AC.hpp
d2_ee_sddp_AD.hpp
d2_ee_sddp_BB.hpp
d2_ee_sddp_BC.hpp
d2_ee_sddp_BD.hpp
d2_ee_sddp_CC.hpp
d2_ee_sddp_CD.hpp
d2_ee_sddp_DD.hpp
d2_ee_sdds_AA.hpp
d2_ee_sdds_AB.hpp
d2_ee_sdds_AC.hpp
d2_ee_sdds_AD.hpp
d2_ee_sdds_BB.hpp
d2_ee_sdds_BC.hpp
d2_ee_sdds_BD.hpp
d2_ee_sdds_CC.hpp
d2_ee_sdds_CD.hpp
d2_ee_sdds_DD.hpp
d2_ee_sdpd_AA.hpp
d2_ee_sdpd_AB.hpp
d2_ee_sdpd_AC.hpp
d2_ee_sdpd_AD.hpp
d2_ee_sdpd_BB.hpp
d2_ee_sdpd_BC.hpp
d2_ee_sdpd_BD.hpp
d2_ee_sdpd_CC.hpp
d2_ee_sdpd_CD.hpp
d2_ee_sdpd_DD.hpp
d2_ee_sdpp_AA.hpp
d2_ee_sdpp_AB.hpp
d2_ee_sdpp_AC.hpp
d2_ee_sdpp_AD.hpp
d2_ee_sdpp_BB.hpp
d2_ee_sdpp_BC.hpp
d2_ee_sdpp_BD.hpp
d2_ee_sdpp_CC.hpp
d2_ee_sdpp_CD.hpp
d2_ee_sdpp_DD.hpp
d2_ee_sdps_AA.hpp
d2_ee_sdps_AB.hpp
d2_ee_sdps_AC.hpp
d2_ee_sdps_AD.hpp
d2_ee_sdps_BB.hpp
d2_ee_sdps_BC.hpp
d2_ee_sdps_BD.hpp
d2_ee_sdps_CC.hpp
d2_ee_sdps_CD.hpp
d2_ee_sdps_DD.hpp
d2_ee_sdsd_AA.hpp
d2_ee_sdsd_AB.hpp
d2_ee_sdsd_AC.hpp
d2_ee_sdsd_AD.hpp
d2_ee_sdsd_BB.hpp
d2_ee_sdsd_BC.hpp
d2_ee_sdsd_BD.hpp
d2_ee_sdsd_CC.hpp
d2_ee_sdsd_CD.hpp
d2_ee_sdsd_DD.hpp
d2_ee_sdsp_AA.hpp
d2_ee_sdsp_AB.hpp
d2_ee_sdsp_AC.hpp
d2_ee_sdsp_AD.hpp
d2_ee_sdsp_BB.hpp
d2_ee_sdsp_BC.hpp
d2_ee_sdsp_BD.hpp
d2_ee_sdsp_CC.hpp
d2_ee_sdsp_CD.hpp
d2_ee_sdsp_DD.hpp
d2_ee_sdss_AA.hpp
d2_ee_sdss_AB.hpp
d2_ee_sdss_AC.hpp
d2_ee_sdss_AD.hpp
d2_ee_sdss_BB.hpp
d2_ee_sdss_BC.hpp
d2_ee_sdss_BD.hpp
d2_ee_sdss_CC.hpp
d2_ee_sdss_CD.hpp
d2_ee_sdss_DD.hpp
d2_ee_spdd_AA.hpp
d2_ee_spdd_AB.hpp
d2_ee_spdd_AC.hpp
d2_ee_spdd_AD.hpp
d2_ee_spdd_BB.hpp
d2_ee_spdd_BC.hpp
d2_ee_spdd_BD.hpp
d2_ee_spdd_CC.hpp
d2_ee_spdd_CD.hpp
d2_ee_spdd_DD.hpp
d2_ee_spdp_AA.hpp
d2_ee_spdp_AB.hpp
d2_ee_spdp_AC.hpp
d2_ee_spdp_AD.hpp
d2_ee_spdp_BB.hpp
d2_ee_spdp_BC.hpp
d2_ee_spdp_BD.hpp
d2_ee_spdp_CC.hpp
d2_ee_spdp_CD.hpp
d2_ee_spdp_DD.hpp
d2_ee_spds_AA.hpp
d2_ee_spds_AB.hpp
d2_ee_spds_AC.hpp
d2_ee_spds_AD.hpp
d2_ee_spds_BB.hpp
d2_ee_spds_BC.hpp
d2_ee_spds_BD.hpp
d2_ee_spds_CC.hpp
d2_ee_spds_CD.hpp
d2_ee_spds_DD.hpp
d2_ee_sppd_AA.hpp
d2_ee_sppd_AB.hpp
d2_ee_sppd_AC.hpp
d2_ee_sppd_AD.hpp
d2_ee_sppd_BB.hpp
d2_ee_sppd_BC.hpp
d2_ee_sppd_BD.hpp
d2_ee_sppd_CC.hpp
d2_ee_sppd_CD.hpp
d2_ee_sppd_DD.hpp
d2_ee_sppp_AA.hpp
d2_ee_sppp_AB.hpp
d2_ee_sppp_AC.hpp
d2_ee_sppp_AD.hpp
d2_ee_sppp_BB.hpp
d2_ee_sppp_BC.hpp
d2_ee_sppp_BD.hpp
d2_ee_sppp_CC.hpp
d2_ee_sppp_CD.hpp
d2_ee_sppp_DD.hpp
d2_ee_spps_AA.hpp
d2_ee_spps_AB.hpp
d2_ee_spps_AC.hpp
d2_ee_spps_AD.hpp
d2_ee_spps_BB.hpp
d2_ee_spps_BC.hpp
d2_ee_spps_BD.hpp
d2_ee_spps_CC.hpp
d2_ee_spps_CD.hpp
d2_ee_spps_DD.hpp
d2_ee_spsd_AA.hpp
d2_ee_spsd_AB.hpp
d2_ee_spsd_AC.hpp
d2_ee_spsd_AD.hpp
d2_ee_spsd_BB.hpp
d2_ee_spsd_BC.hpp
d2_ee_spsd_BD.hpp
d2_ee_spsd_CC.hpp
d2_ee_spsd_CD.hpp
d2_ee_spsd_DD.hpp
d2_ee_spsp_AA.hpp
d2_ee_spsp_AB.hpp
d2_ee_spsp_AC.hpp
d2_ee_spsp_AD.hpp
d2_ee_spsp_BB.hpp
d2_ee_spsp_BC.hpp
d2_ee_spsp_BD.hpp
d2_ee_spsp_CC.hpp
d2_ee_spsp_CD.hpp
d2_ee_spsp_DD.hpp
d2_ee_spss_AA.hpp
d2_ee_spss_AB.hpp
d2_ee_spss_AC.hpp
d2_ee_spss_AD.hpp
d2_ee_spss_BB.hpp
d2_ee_spss_BC.hpp
d2_ee_spss_BD.hpp
d2_ee_spss_CC.hpp
d2_ee_spss_CD.hpp
d2_ee_spss_DD.hpp
d2_ee_ssdd_AA.hpp
d2_ee_ssdd_AB.hpp
d2_ee_ssdd_AC.hpp
d2_ee_ssdd_AD.hpp
d2_ee_ssdd_BB.hpp
d2_ee_ssdd_BC.hpp
d2_ee_ssdd_BD.hpp
d2_ee_ssdd_CC.hpp
d2_ee_ssdd_CD.hpp
d2_ee_ssdd_DD.hpp
d2_ee_ssdp_AA.hpp
d2_ee_ssdp_AB.hpp
d2_ee_ssdp_AC.hpp
d2_ee_ssdp_AD.hpp
d2_ee_ssdp_BB.hpp
d2_ee_ssdp_BC.hpp
d2_ee_ssdp_BD.hpp
d2_ee_ssdp_CC.hpp
d2_ee_ssdp_CD.hpp
d2_ee_ssdp_DD.hpp
d2_ee_ssds_AA.hpp
d2_ee_ssds_AB.hpp
d2_ee_ssds_AC.hpp
d2_ee_ssds_AD.hpp
d2_ee_ssds_BB.hpp
d2_ee_ssds_BC.hpp
d2_ee_ssds_BD.hpp
d2_ee_ssds_CC.hpp
d2_ee_ssds_CD.hpp
d2_ee_ssds_DD.hpp
d2_ee_sspd_AA.hpp
d2_ee_sspd_AB.hpp
d2_ee_sspd_AC.hpp
d2_ee_sspd_AD.hpp
d2_ee_sspd_BB.hpp
d2_ee_sspd_BC.hpp
d2_ee_sspd_BD.hpp
d2_ee_sspd_CC.hpp
d2_ee_sspd_CD.hpp
d2_ee_sspd_DD.hpp
d2_ee_sspp_AA.hpp
d2_ee_sspp_AB.hpp
d2_ee_sspp_AC.hpp
d2_ee_sspp_AD.hpp
d2_ee_sspp_BB.hpp
d2_ee_sspp_BC.hpp
d2_ee_sspp_BD.hpp
d2_ee_sspp_CC.hpp
d2_ee_sspp_CD.hpp
d2_ee_sspp_DD.hpp
d2_ee_ssps_AA.hpp
d2_ee_ssps_AB.hpp
d2_ee_ssps_AC.hpp
d2_ee_ssps_AD.hpp
d2_ee_ssps_BB.hpp
d2_ee_ssps_BC.hpp
d2_ee_ssps_BD.hpp
d2_ee_ssps_CC.hpp
d2_ee_ssps_CD.hpp
d2_ee_ssps_DD.hpp
d2_ee_sssd_AA.hpp
d2_ee_sssd_AB.hpp
d2_ee_sssd_AC.hpp
d2_ee_sssd_AD.hpp
d2_ee_sssd_BB.hpp
d2_ee_sssd_BC.hpp
d2_ee_sssd_BD.hpp
d2_ee_sssd_CC.hpp
d2_ee_sssd_CD.hpp
d2_ee_sssd_DD.hpp
d2_ee_sssp_AA.hpp
d2_ee_sssp_AB.hpp
d2_ee_sssp_AC.hpp
d2_ee_sssp_AD.hpp
d2_ee_sssp_BB.hpp
d2_ee_sssp_BC.hpp
d2_ee_sssp_BD.hpp
d2_ee_sssp_CC.hpp
d2_ee_sssp_CD.hpp
d2_ee_sssp_DD.hpp
d2_ee_ssss_AA.hpp
d2_ee_ssss_AB.hpp
d2_ee_ssss_AC.hpp
d2_ee_ssss_AD.hpp
d2_ee_ssss_BB.hpp
d2_ee_ssss_BC.hpp
d2_ee_ssss_BD.hpp
d2_ee_ssss_CC.hpp
d2_ee_ssss_CD.hpp
d2_ee_ssss_DD.hpp
	d2_kinetic.hpp
	d2_ne_dd_AA.hpp
	d2_ne_dd_AB.hpp
	d2_ne_dd_AC.hpp
	d2_ne_dd_BB.hpp
	d2_ne_dd_BC.hpp
	d2_ne_dd_CC.hpp
	d2_ne_dp_AA.hpp
	d2_ne_dp_AB.hpp
	d2_ne_dp_AC.hpp
	d2_ne_dp_BB.hpp
	d2_ne_dp_BC.hpp
	d2_ne_dp_CC.hpp
	d2_ne_ds_AA.hpp
	d2_ne_ds_AB.hpp
	d2_ne_ds_AC.hpp
	d2_ne_ds_BB.hpp
	d2_ne_ds_BC.hpp
	d2_ne_ds_CC.hpp
	d2_ne_pd_AA.hpp
	d2_ne_pd_AB.hpp
	d2_ne_pd_AC.hpp
	d2_ne_pd_BB.hpp
	d2_ne_pd_BC.hpp
	d2_ne_pd_CC.hpp
	d2_ne_pp_AA.hpp
	d2_ne_pp_AB.hpp
	d2_ne_pp_AC.hpp
	d2_ne_pp_BB.hpp
	d2_ne_pp_BC.hpp
	d2_ne_pp_CC.hpp
	d2_ne_ps_AA.hpp
	d2_ne_ps_AB.hpp
	d2_ne_ps_AC.hpp
	d2_ne_ps_BB.hpp
	d2_ne_ps_BC.hpp
	d2_ne_ps_CC.hpp
	d2_ne_sd_AA.hpp
	d2_ne_sd_AB.hpp
	d2_ne_sd_AC.hpp
	d2_ne_sd_BB.hpp
	d2_ne_sd_BC.hpp
	d2_ne_sd_CC.hpp
	d2_ne_sp_AA.hpp
	d2_ne_sp_AB.hpp
	d2_ne_sp_AC.hpp
	d2_ne_sp_BB.hpp
	d2_ne_sp_BC.hpp
	d2_ne_sp_CC.hpp
	d2_ne_ss_AA.hpp
	d2_ne_ss_AB.hpp
	d2_ne_ss_AC.hpp
	d2_ne_ss_BB.hpp
	d2_ne_ss_BC.hpp
	d2_ne_ss_CC.hpp
	d2_overlap.hpp
	)

set ( TESTS 
	gto_d2_kit_test.cpp
	kinetic_test.cpp
	overlap_test.cpp
	vee_test.cpp
	vne_test.cpp)

#file( GLOB SRCS ${CMAKE_SOURCE_DIR}/src/*.ey )
#file( GLOB HEADERS ${CMAKE_SOURCE_DIR}/include/automateusz/*.hpp )
#file( GLOB TESTS ${CMAKE_SOURCE_DIR}/test/src/*.cpp )
file( GLOB CPP ${CMAKE_SOURCE_DIR}/src/*.cpp )

find_program (YACAS yacas)
if (NOT YACAS)
  message (FATAL_ERROR "yacas not found, bailing out")
endif ()

exec_program (${YACAS} ARGS -v OUTPUT_VARIABLE YACAS_VERSION)
if (${YACAS_VERSION} VERSION_LESS "1.5.0")
  message (FATAL_ERROR "found yacas version ${YACAS_VERSION}, but yacas 1.5.0 required, bailing out")
endif ()

message (STATUS "Found yacas ${YACAS_VERSION}")

exec_program (${YACAS} ARGS -d OUTPUT_VARIABLE YACAS_ROOTDIR)
set (YACAS_ROOTDIR yacas_scripts:${YACAS_ROOTDIR})

file (MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/gto_d2_kit)
file (MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/gto_d2_kit/src)
file (MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/gto_d2_kit/include)
file (MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/gto_d2_kit/include/gto_d2_kit)
file (MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/gto_d2_kit/test)
file (MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/gto_d2_kit/test/src)

set( CMakeListsTests )
set( TESTS_SRCS)
set( HEADERS_TO_COPY )
set( CPP_TO_COPY )

set (TO "${PROJECT_BINARY_DIR}/gto_d2_kit/test/CMakeLists.txt")
set (FROM "${PROJECT_SOURCE_DIR}/test/CMakeLists.txt" ) 
add_custom_command (
    OUTPUT "${TO}"
    COMMAND cmake -E copy_if_different  ${FROM} ${TO}
    DEPENDS "${FROM}"
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Copying from ${FROM} to ${TO}")
list (APPEND CMakeListsTests "${TO}")

copy_files_if_different( TESTS ${PROJECT_SOURCE_DIR}/test/src ${PROJECT_BINARY_DIR}/gto_d2_kit/test/src TESTS_SRCS )
copy_files_if_different( HEADERS ${PROJECT_SOURCE_DIR}/include/gto_d2_kit ${PROJECT_BINARY_DIR}/gto_d2_kit/include/gto_d2_kit HEADERS_TO_COPY )
copy_files_if_different( CPP ${PROJECT_SOURCE_DIR}/src ${PROJECT_BINARY_DIR}/gto_d2_kit/src CPP_TO_COPY )

set (GENERATED_SRCS)
foreach (S ${SRCS})
  get_filename_component (T "${S}" NAME)
  set (T "${PROJECT_BINARY_DIR}/gto_d2_kit/src/${T}.cpp")
  add_custom_command (
    OUTPUT "${T}"
    COMMAND ${YACAS} ARGS -pc --rootdir ${YACAS_ROOTDIR} --patchload "${S}" > "${T}"
    DEPENDS "${S}"
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Generating CXX source from ${S}")
  list (APPEND GENERATED_SRCS "${T}")
endforeach ()

#configure_file(CMakeLists.txt.in ${CMAKE_BINARY_DIR}/gto_d2_kit/CMakeLists.txt @ONLY)

add_custom_target (gto_d2_kit ALL DEPENDS ${GENERATED_SRCS} ${CMAKE_BINARY_DIR}/gto_d2_kit/CMakeLists.txt 
	${CMakeListsTests} ${TESTS_SRCS} ${HEADERS_TO_COPY} ${CPP_TO_COPY})

file(APPEND ${CMAKE_BINARY_DIR}/gto_d2_kit/CMakeLists.txt "enable_testing ()\n" )
file(APPEND ${CMAKE_BINARY_DIR}/gto_d2_kit/CMakeLists.txt "add_subdirectory (test)\n" )
