#ifndef __QMI_NAS_H__
#define __QMI_NAS_H__

#include <stdint.h>
#include <stdbool.h>

#include "libqrtr.h"

extern struct qmi_elem_info nas_register_indications_req_ei[];
extern struct qmi_elem_info nas_get_signal_strength_req_ei[];
extern struct qmi_elem_info nas_get_signal_strength_resp_ei[];
extern struct qmi_elem_info nas_initiate_network_register_ei[];
extern struct qmi_elem_info nas_serving_system_resp_ei[];
extern struct qmi_elem_info nas_serving_system_ind_ei[];
extern struct qmi_elem_info nas_set_operating_mode_req_ei[];
extern struct qmi_elem_info nas_set_operating_mode_resp_ei[];
extern struct qmi_elem_info nas_set_system_prefs_ei[];
extern struct qmi_elem_info nas_get_system_prefs_ei[];
extern struct qmi_elem_info nas_get_operator_name_resp_ei[];
extern struct qmi_elem_info nas_operator_name_ind_ei[];
extern struct qmi_elem_info nas_get_cell_loc_info_ei[];
extern struct qmi_elem_info nas_get_plmn_name_req_ei[];
extern struct qmi_elem_info nas_get_plmn_name_resp_ei[];
extern struct qmi_elem_info nas_get_signal_info_ei[];
extern struct qmi_elem_info nas_signal_info_ind_ei[];
extern struct qmi_elem_info nas_get_lte_cphy_ca_info_resp_ei[];

#define QMI_NAS_EVENT_REPORT 2
#define QMI_NAS_REGISTER_INDICATIONS 3
#define QMI_NAS_INITIATE_NETWORK_REGISTER 34
#define QMI_NAS_SERVING_SYSTEM_REPORT 36
#define QMI_NAS_SET_SYSTEM_PREFS 51
#define QMI_NAS_GET_SYSTEM_PREFS 52
#define QMI_NAS_GET_OPERATOR_NAME 57
#define QMI_NAS_GET_CELL_LOCATION_INFO 67
#define QMI_NAS_GET_PLMN_NAME 68
#define QMI_NAS_SUBSCRIPTION_INFO_REPORT 72
#define QMI_NAS_GET_SIGNAL_INFO 79
#define QMI_NAS_SIGNAL_INFO_REPORT 81
#define QMI_NAS_ERROR_RATE_REPORT 83
#define QMI_NAS_RF_BAND_INFO_REPORT 102
#define QMI_NAS_FORCE_NETWORK_SEARCH 103
#define QMI_NAS_GET_LTE_CPY_CA_INFO 172
#define QMI_NAS_DL_BANDWIDTH_1_4 0
#define QMI_NAS_DL_BANDWIDTH_3 1
#define QMI_NAS_DL_BANDWIDTH_5 2
#define QMI_NAS_DL_BANDWIDTH_10 3
#define QMI_NAS_DL_BANDWIDTH_15 4
#define QMI_NAS_DL_BANDWIDTH_20 5
#define QMI_NAS_DL_BANDWIDTH_INVALID 6
#define QMI_NAS_SIGNAL_STRENGTH_REQUEST_NONE 0
#define QMI_NAS_SIGNAL_STRENGTH_REQUEST_RSSI 1
#define QMI_NAS_SIGNAL_STRENGTH_REQUEST_ECIO 2
#define QMI_NAS_SIGNAL_STRENGTH_REQUEST_IO 4
#define QMI_NAS_SIGNAL_STRENGTH_REQUEST_SINR 8
#define QMI_NAS_SIGNAL_STRENGTH_REQUEST_ERROR_RATE 16
#define QMI_NAS_SIGNAL_STRENGTH_REQUEST_RSRQ 32
#define QMI_NAS_SIGNAL_STRENGTH_REQUEST_LTE_SNR 64
#define QMI_NAS_SIGNAL_STRENGTH_REQUEST_LTE_RSRP 128
#define QMI_NAS_GET_SIGNAL_STRENGTH 32
#define QMI_NAS_REGISTRATION_STATE_NOT_REGISTERED 0
#define QMI_NAS_REGISTRATION_STATE_REGISTERED 1
#define QMI_NAS_REGISTRATION_STATE_NOT_REGISTERED_SEARCHING 2
#define QMI_NAS_REGISTRATION_STATE_REGISTRATION_DENIED 3
#define QMI_NAS_REGISTRATION_STATE_UNKNOWN 4
#define QMI_NAS_ATTACH_STATE_UNKNOWN 0
#define QMI_NAS_ATTACH_STATE_ATTACHED 1
#define QMI_NAS_ATTACH_STATE_DETACHED 2
#define QMI_NAS_RADIO_INTERFACE_UNKNOWN 255
#define QMI_NAS_RADIO_INTERFACE_NONE 0
#define QMI_NAS_RADIO_INTERFACE_CDMA_1X 1
#define QMI_NAS_RADIO_INTERFACE_CDMA_1XEVDO 2
#define QMI_NAS_RADIO_INTERFACE_AMPS 3
#define QMI_NAS_RADIO_INTERFACE_GSM 4
#define QMI_NAS_RADIO_INTERFACE_UMTS 5
#define QMI_NAS_RADIO_INTERFACE_LTE 8
#define QMI_NAS_RADIO_INTERFACE_TD_SCDMA 9
#define QMI_NAS_RADIO_INTERFACE_5GNR 12

struct nas_signal_strength {
	int8_t strength;
	int8_t interface;
};

struct nas_ss_value {
	uint8_t val;
	int8_t interface;
};

struct nas_network_reject_info {
	uint8_t enable_network_reject_indications;
	uint8_t suppress_system_info_indications;
};

struct nas_lte_cphy_agg_scell {
	uint16_t pci;
	uint16_t rx_chan;
	uint32_t dl_bandwidth;
	uint16_t lte_band;
	uint32_t state;
};

struct nas_serving_system {
	uint8_t registration_state;
	uint8_t cs_attach_state;
	uint8_t ps_attach_state;
	uint8_t selected_network;
	uint8_t radio_interfaces_len;
	uint8_t *radio_interfaces;
};

struct nas_current_plmn {
	uint16_t mcc;
	uint16_t mnc;
	uint32_t description_len;
	char description[256];
};

struct nas_service_status {
	uint8_t status;
	uint8_t capability;
	uint8_t hdr_status;
	uint8_t hdr_hybrid;
	uint8_t forbidden;
};

struct nas_service_provider_name {
	uint8_t display_condition;
	uint32_t name_len;
	char name[256];
};

struct nas_operator_plmn {
	char mcc[3];
	char mnc[3];
	uint16_t lac1;
	uint16_t lac2;
	uint8_t name_record_indicator;
};

struct nas_operator_plmn_arr_operators {
	char mcc[3];
	char mnc[3];
	uint16_t lac1;
	uint16_t lac2;
	uint8_t name_record_indicator;
};

struct nas_operator_plmn_arr {
	uint16_t operators_len;
	struct nas_operator_plmn_arr_operators *operators;
};

struct nas_operator_plmn_name {
	uint8_t name_encoding;
	uint8_t short_country_initials;
	uint8_t long_name_spare_bits;
	uint8_t short_name_spare_bits;
	uint8_t long_name_len;
	uint8_t *long_name;
	uint8_t short_name_len;
	uint8_t *short_name;
};

struct nas_operator_plmn_name_arr_operators {
	uint8_t name_encoding;
	uint8_t short_country_initials;
	uint8_t long_name_spare_bits;
	uint8_t short_name_spare_bits;
	uint8_t long_name_len;
	uint8_t *long_name;
	uint8_t short_name_len;
	uint8_t *short_name;
};

struct nas_operator_plmn_name_arr {
	uint8_t operators_len;
	struct nas_operator_plmn_name_arr_operators *operators;
};

struct nas_network_selection_pref {
	uint8_t mode;
	uint16_t mcc;
	uint16_t mnc;
};

struct nas_geran_info_cells {
	uint32_t cell_id;
	uint8_t plmn[3];
	uint16_t lac;
	uint16_t abs_channel_num;
	uint8_t bsic;
	uint16_t rx_level;
};

struct nas_geran_info {
	uint32_t cell_id;
	uint8_t plmn[3];
	uint16_t lac;
	uint16_t abs_channel_num;
	uint8_t bsic;
	uint32_t timing_advance;
	uint16_t rx_level;
	uint8_t cells_len;
	struct nas_geran_info_cells *cells;
};

struct nas_umts_info_cells {
	uint16_t abs_channel_num;
	uint16_t psc;
	int16_t rscp;
	int16_t ecio;
};

struct nas_umts_info_gerans {
	uint16_t abs_channel_num;
	uint8_t network_color_code;
	uint8_t base_station_color_code;
	int8_t rssi;
};

struct nas_umts_info {
	uint16_t cell_id;
	uint8_t plmn[3];
	uint16_t lac;
	uint16_t abs_channel_num;
	uint16_t psc;
	int16_t rscp;
	int16_t ecio;
	uint8_t cells_len;
	struct nas_umts_info_cells *cells;
	uint8_t gerans_len;
	struct nas_umts_info_gerans *gerans;
};

struct nas_cdma_info {
	uint16_t system_id;
	uint16_t network_id;
	uint16_t bsid;
	uint16_t reference_pn;
	uint32_t latitude;
	uint32_t longitude;
};

struct nas_intrafreq_lte_info_cells {
	uint16_t pci;
	int16_t rsrq;
	int16_t rsrp;
	int16_t rssi;
	int16_t rx_level;
};

struct nas_intrafreq_lte_info {
	uint8_t ue_idle;
	uint8_t plmn[3];
	uint16_t tac;
	uint32_t global_cell_id;
	uint16_t abs_channel_num;
	uint16_t serving_cell_id;
	uint8_t crp;
	uint8_t s_non_intra_search_threshold;
	uint8_t serving_cell_low_threshold;
	uint8_t s_intra_search_threshold;
	uint8_t cells_len;
	struct nas_intrafreq_lte_info_cells *cells;
};

struct nas_plmn_id {
	uint16_t mcc;
	uint16_t mnc;
};

struct nas_eons_plmn_name {
	uint8_t sp_name_encoding;
	uint8_t sp_name_len;
	uint8_t *sp_name;
	uint8_t short_name_encoding;
	uint8_t short_name_country_initials;
	uint8_t short_name_spare_bits;
	uint8_t short_name_len;
	uint8_t *short_name;
	uint8_t long_name_encoding;
	uint8_t long_name_country_initials;
	uint8_t long_name_spare_bits;
	uint8_t long_name_len;
	uint8_t *long_name;
};

struct nas_ss_cdma {
	int8_t rssi;
	int16_t ecio;
};

struct nas_ss_hdr {
	int8_t rssi;
	int16_t ecio;
	uint8_t sinr;
	int32_t io;
};

struct nas_ss_wcdma {
	int8_t rssi;
	int16_t ecio;
};

struct nas_ss_lte {
	int8_t rssi;
	int8_t rsrq;
	int16_t rsrp;
	int16_t snr;
};

struct nas_ss_tdma_ext {
	uint32_t rssi;
	int32_t rscp;
	int32_t ecio;
	int32_t sinr;
};

struct nas_register_indications_req { // 0x0003
	struct qmi_message_header header;
	uint8_t system_selection_preference;  // 0x10
	uint8_t ddtm_events;  // 0x12
	uint8_t serving_system_events;  // 0x13
	uint8_t dual_standby_preference;  // 0x14
	uint8_t subscription_info;  // 0x15
	uint8_t network_time;  // 0x17
	uint8_t system_info;  // 0x18
	uint8_t signal_info;  // 0x19
	uint8_t error_rate;  // 0x1a
	uint8_t hdr_new_uati_assigned;  // 0x1b
	uint8_t hdr_session_closed;  // 0x1c
	uint8_t managed_roaming;  // 0x1d
	uint8_t current_plmn_name;  // 0x1e
	uint8_t embms_status;  // 0x1f
	uint8_t rf_band_information;  // 0x20
	struct nas_network_reject_info network_reject_information;  // 0x21
};

struct nas_get_signal_strength_req { // 0x0020
	struct qmi_message_header header;
	uint16_t mask;  // 0x10
};

struct nas_get_signal_strength_resp { // 0x0020
	struct qmi_message_header header;
	bool strength_valid;
	struct nas_signal_strength strength;  // 0x01
	struct qmi_response_type_v01 res;  // 0x02
	bool strength_list_valid;
	uint32_t strength_list_len;
	struct nas_signal_strength strength_list[16];  // 0x10
	bool rssi_list_valid;
	uint32_t rssi_list_len;
	struct nas_ss_value rssi_list[1];  // 0x11
	bool ecio_list_valid;
	uint32_t ecio_list_len;
	struct nas_ss_value ecio_list[1];  // 0x12
	bool io_valid;
	uint32_t io;  // 0x13
	bool sinr_valid;
	uint8_t sinr;  // 0x14
	bool err_rate_list_valid;
	uint32_t err_rate_list_len;
	struct nas_ss_value err_rate_list[16];  // 0x15
	bool rsrq_valid;
	struct nas_ss_value rsrq;  // 0x16
	bool lte_snr_valid;
	int16_t lte_snr;  // 0x17
	bool lte_rsrp_valid;
	int16_t lte_rsrp;  // 0x18
};

struct nas_initiate_network_register { // 0x0022
	struct qmi_message_header header;
	uint8_t action;  // 0x01
};

struct nas_serving_system_resp { // 0x0024
	struct qmi_message_header header;
	struct qmi_response_type_v01 res;  // 0x02
	bool system_valid;
	struct nas_serving_system system;  // 0x01
	bool data_service_cap_valid;
	uint32_t data_service_cap_len;
	uint8_t data_service_cap[16];  // 0x11
	bool plmn_valid;
	struct nas_current_plmn plmn;  // 0x12
	bool lac_valid;
	uint16_t lac;  // 0x1d
	bool cid_valid;
	uint16_t cid;  // 0x1e
	bool status_valid;
	struct nas_service_status status;  // 0x22
};

struct nas_serving_system_ind { // 0x0024
	struct qmi_message_header header;
	bool system_valid;
	struct nas_serving_system system;  // 0x01
	bool data_service_cap_valid;
	uint32_t data_service_cap_len;
	uint8_t data_service_cap[16];  // 0x11
	bool plmn_valid;
	struct nas_current_plmn plmn;  // 0x12
	bool lac_valid;
	uint16_t lac;  // 0x1d
	bool cid_valid;
	uint16_t cid;  // 0x1e
	bool status_valid;
	struct nas_service_status status;  // 0x22
};

struct nas_set_operating_mode_req { // 0x002e
	struct qmi_message_header header;
	uint8_t mode;  // 0x01
};

struct nas_set_operating_mode_resp { // 0x002e
	struct qmi_message_header header;
	struct qmi_response_type_v01 res;  // 0x02
};

struct nas_set_system_prefs { // 0x0033
	struct qmi_message_header header;
	bool network_selection_valid;
	struct nas_network_selection_pref network_selection;  // 0x16
};

struct nas_get_system_prefs { // 0x0034
	struct qmi_message_header header;
	struct qmi_response_type_v01 res;  // 0x02
	bool network_selection_valid;
	uint8_t network_selection;  // 0x16
};

struct nas_get_operator_name_resp { // 0x0039
	struct qmi_message_header header;
	struct qmi_response_type_v01 res;  // 0x02
	bool provider_name_valid;
	struct nas_service_provider_name provider_name;  // 0x10
	bool operator_plmns_valid;
	struct nas_operator_plmn_arr operator_plmns;  // 0x11
	bool operator_plmn_names_valid;
	struct nas_operator_plmn_name_arr operator_plmn_names;  // 0x12
	uint32_t operator_string_name_len;
	char operator_string_name[256]; // 0x13
	bool nitz_info_valid;
	struct nas_operator_plmn_name nitz_info;  // 0x14
};

struct nas_operator_name_ind { // 0x003a
	struct qmi_message_header header;
	bool provider_name_valid;
	struct nas_service_provider_name provider_name;  // 0x10
	bool operator_plmns_valid;
	struct nas_operator_plmn_arr operator_plmns;  // 0x11
	bool operator_plmn_names_valid;
	struct nas_operator_plmn_name_arr operator_plmn_names;  // 0x12
	uint32_t operator_string_name_len;
	char operator_string_name[256]; // 0x13
	bool nitz_info_valid;
	struct nas_operator_plmn_name nitz_info;  // 0x14
};

struct nas_get_cell_loc_info { // 0x0043
	struct qmi_message_header header;
	struct qmi_response_type_v01 res;  // 0x02
	bool geran_valid;
	struct nas_geran_info geran;  // 0x10
	bool umts_valid;
	struct nas_umts_info umts;  // 0x11
	bool cdma_valid;
	struct nas_cdma_info cdma;  // 0x12
	bool intra_lte_valid;
	struct nas_intrafreq_lte_info intra_lte;  // 0x13
};

struct nas_get_plmn_name_req { // 0x0044
	struct qmi_message_header header;
	struct nas_plmn_id plmn;  // 0x01
	bool send_all_info_valid;
	uint8_t send_all_info;  // 0x16
};

struct nas_get_plmn_name_resp { // 0x0044
	struct qmi_message_header header;
	struct qmi_response_type_v01 res;  // 0x02
	bool plmn_name_valid;
	struct nas_eons_plmn_name plmn_name;  // 0x10
};

struct nas_get_signal_info { // 0x004f
	struct qmi_message_header header;
	struct qmi_response_type_v01 res;  // 0x02
	bool cdma_valid;
	struct nas_ss_cdma cdma;  // 0x10
	bool hdr_valid;
	struct nas_ss_hdr hdr;  // 0x11
	bool gsm_valid;
	int8_t gsm;  // 0x12
	bool wcdma_valid;
	struct nas_ss_wcdma wcdma;  // 0x13
	bool lte_valid;
	struct nas_ss_lte lte;  // 0x14
	bool tdma_valid;
	int8_t tdma;  // 0x15
	bool tdma_ext_valid;
	struct nas_ss_tdma_ext tdma_ext;  // 0x16
};

struct nas_signal_info_ind { // 0x0051
	struct qmi_message_header header;
	bool cdma_valid;
	struct nas_ss_cdma cdma;  // 0x10
	bool hdr_valid;
	struct nas_ss_hdr hdr;  // 0x11
	bool gsm_valid;
	int8_t gsm;  // 0x12
	bool wcdma_valid;
	struct nas_ss_wcdma wcdma;  // 0x13
	bool lte_valid;
	struct nas_ss_lte lte;  // 0x14
	bool tdma_valid;
	int8_t tdma;  // 0x15
};

struct nas_get_lte_cphy_ca_info_resp { // 0x00ac
	struct qmi_message_header header;
	struct qmi_response_type_v01 res;  // 0x02
	bool dl_bandwidth_valid;
	uint32_t dl_bandwidth;  // 0x11
	bool phy_scell_info_valid;
	struct nas_lte_cphy_agg_scell phy_scell_info;  // 0x12
};

#define NAS_REGISTER_INDICATIONS_REQ_NEW ({ \
	struct nas_register_indications_req *ptr = malloc(sizeof(struct nas_register_indications_req)); \
	ptr->qmi_header->type = 0; ptr->qmi_header->msg_id = 0x0003; \
	ptr->ei = &nas_register_indications_req_ei; ptr })
#define NAS_REGISTER_INDICATIONS_REQ_INITIALIZER { { 0, 0, 0x0003, 0 }, &nas_register_indications_req_ei, "register_indications_req", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, {} }
#define NAS_GET_SIGNAL_STRENGTH_REQ_NEW ({ \
	struct nas_get_signal_strength_req *ptr = malloc(sizeof(struct nas_get_signal_strength_req)); \
	ptr->qmi_header->type = 0; ptr->qmi_header->msg_id = 0x0020; \
	ptr->ei = &nas_get_signal_strength_req_ei; ptr })
#define NAS_GET_SIGNAL_STRENGTH_REQ_INITIALIZER { { 0, 0, 0x0020, 0 }, &nas_get_signal_strength_req_ei, "get_signal_strength_req", 0 }
#define NAS_GET_SIGNAL_STRENGTH_RESP_NEW ({ \
	struct nas_get_signal_strength_resp *ptr = malloc(sizeof(struct nas_get_signal_strength_resp)); \
	ptr->qmi_header->type = 2; ptr->qmi_header->msg_id = 0x0020; \
	ptr->ei = &nas_get_signal_strength_resp_ei; ptr })
#define NAS_GET_SIGNAL_STRENGTH_RESP_INITIALIZER { { 2, 0, 0x0020, 0 }, &nas_get_signal_strength_resp_ei, "get_signal_strength_resp", {}, {}, {}, {}, {}, 0, 0, {}, {}, 0, 0 }
#define NAS_INITIATE_NETWORK_REGISTER_NEW ({ \
	struct nas_initiate_network_register *ptr = malloc(sizeof(struct nas_initiate_network_register)); \
	ptr->qmi_header->type = 0; ptr->qmi_header->msg_id = 0x0022; \
	ptr->ei = &nas_initiate_network_register_ei; ptr })
#define NAS_INITIATE_NETWORK_REGISTER_INITIALIZER { { 0, 0, 0x0022, 0 }, &nas_initiate_network_register_ei, "initiate_network_register", 0 }
#define NAS_SERVING_SYSTEM_RESP_NEW ({ \
	struct nas_serving_system_resp *ptr = malloc(sizeof(struct nas_serving_system_resp)); \
	ptr->qmi_header->type = 2; ptr->qmi_header->msg_id = 0x0024; \
	ptr->ei = &nas_serving_system_resp_ei; ptr })
#define NAS_SERVING_SYSTEM_RESP_INITIALIZER { { 2, 0, 0x0024, 0 }, &nas_serving_system_resp_ei, "serving_system_resp", {}, {}, 0, {}, 0, 0, {} }
#define NAS_SERVING_SYSTEM_IND_NEW ({ \
	struct nas_serving_system_ind *ptr = malloc(sizeof(struct nas_serving_system_ind)); \
	ptr->qmi_header->type = 4; ptr->qmi_header->msg_id = 0x0024; \
	ptr->ei = &nas_serving_system_ind_ei; ptr })
#define NAS_SERVING_SYSTEM_IND_INITIALIZER { { 4, 0, 0x0024, 0 }, &nas_serving_system_ind_ei, "serving_system_ind", {}, 0, {}, 0, 0, {} }
#define NAS_SET_OPERATING_MODE_REQ_NEW ({ \
	struct nas_set_operating_mode_req *ptr = malloc(sizeof(struct nas_set_operating_mode_req)); \
	ptr->qmi_header->type = 0; ptr->qmi_header->msg_id = 0x002e; \
	ptr->ei = &nas_set_operating_mode_req_ei; ptr })
#define NAS_SET_OPERATING_MODE_REQ_INITIALIZER { { 0, 0, 0x002e, 0 }, &nas_set_operating_mode_req_ei, "set_operating_mode_req", 0 }
#define NAS_SET_OPERATING_MODE_RESP_NEW ({ \
	struct nas_set_operating_mode_resp *ptr = malloc(sizeof(struct nas_set_operating_mode_resp)); \
	ptr->qmi_header->type = 0; ptr->qmi_header->msg_id = 0x002e; \
	ptr->ei = &nas_set_operating_mode_resp_ei; ptr })
#define NAS_SET_OPERATING_MODE_RESP_INITIALIZER { { 0, 0, 0x002e, 0 }, &nas_set_operating_mode_resp_ei, "set_operating_mode_resp", {} }
#define NAS_SET_SYSTEM_PREFS_NEW ({ \
	struct nas_set_system_prefs *ptr = malloc(sizeof(struct nas_set_system_prefs)); \
	ptr->qmi_header->type = 0; ptr->qmi_header->msg_id = 0x0033; \
	ptr->ei = &nas_set_system_prefs_ei; ptr })
#define NAS_SET_SYSTEM_PREFS_INITIALIZER { { 0, 0, 0x0033, 0 }, &nas_set_system_prefs_ei, "set_system_prefs", {} }
#define NAS_GET_SYSTEM_PREFS_NEW ({ \
	struct nas_get_system_prefs *ptr = malloc(sizeof(struct nas_get_system_prefs)); \
	ptr->qmi_header->type = 2; ptr->qmi_header->msg_id = 0x0034; \
	ptr->ei = &nas_get_system_prefs_ei; ptr })
#define NAS_GET_SYSTEM_PREFS_INITIALIZER { { 2, 0, 0x0034, 0 }, &nas_get_system_prefs_ei, "get_system_prefs", {}, 0 }
#define NAS_GET_OPERATOR_NAME_RESP_NEW ({ \
	struct nas_get_operator_name_resp *ptr = malloc(sizeof(struct nas_get_operator_name_resp)); \
	ptr->qmi_header->type = 2; ptr->qmi_header->msg_id = 0x0039; \
	ptr->ei = &nas_get_operator_name_resp_ei; ptr })
#define NAS_GET_OPERATOR_NAME_RESP_INITIALIZER { { 2, 0, 0x0039, 0 }, &nas_get_operator_name_resp_ei, "get_operator_name_resp", {}, {}, {}, {}, 0, NULL, {} }
#define NAS_OPERATOR_NAME_IND_NEW ({ \
	struct nas_operator_name_ind *ptr = malloc(sizeof(struct nas_operator_name_ind)); \
	ptr->qmi_header->type = 4; ptr->qmi_header->msg_id = 0x003a; \
	ptr->ei = &nas_operator_name_ind_ei; ptr })
#define NAS_OPERATOR_NAME_IND_INITIALIZER { { 4, 0, 0x003a, 0 }, &nas_operator_name_ind_ei, "operator_name_ind", {}, {}, {}, 0, NULL, {} }
#define NAS_GET_CELL_LOC_INFO_NEW ({ \
	struct nas_get_cell_loc_info *ptr = malloc(sizeof(struct nas_get_cell_loc_info)); \
	ptr->qmi_header->type = 2; ptr->qmi_header->msg_id = 0x0043; \
	ptr->ei = &nas_get_cell_loc_info_ei; ptr })
#define NAS_GET_CELL_LOC_INFO_INITIALIZER { { 2, 0, 0x0043, 0 }, &nas_get_cell_loc_info_ei, "get_cell_loc_info", {}, {}, {}, {}, {} }
#define NAS_GET_PLMN_NAME_REQ_NEW ({ \
	struct nas_get_plmn_name_req *ptr = malloc(sizeof(struct nas_get_plmn_name_req)); \
	ptr->qmi_header->type = 0; ptr->qmi_header->msg_id = 0x0044; \
	ptr->ei = &nas_get_plmn_name_req_ei; ptr })
#define NAS_GET_PLMN_NAME_REQ_INITIALIZER { { 0, 0, 0x0044, 0 }, &nas_get_plmn_name_req_ei, "get_plmn_name_req", {}, 0 }
#define NAS_GET_PLMN_NAME_RESP_NEW ({ \
	struct nas_get_plmn_name_resp *ptr = malloc(sizeof(struct nas_get_plmn_name_resp)); \
	ptr->qmi_header->type = 2; ptr->qmi_header->msg_id = 0x0044; \
	ptr->ei = &nas_get_plmn_name_resp_ei; ptr })
#define NAS_GET_PLMN_NAME_RESP_INITIALIZER { { 2, 0, 0x0044, 0 }, &nas_get_plmn_name_resp_ei, "get_plmn_name_resp", {}, {} }
#define NAS_GET_SIGNAL_INFO_NEW ({ \
	struct nas_get_signal_info *ptr = malloc(sizeof(struct nas_get_signal_info)); \
	ptr->qmi_header->type = 2; ptr->qmi_header->msg_id = 0x004f; \
	ptr->ei = &nas_get_signal_info_ei; ptr })
#define NAS_GET_SIGNAL_INFO_INITIALIZER { { 2, 0, 0x004f, 0 }, &nas_get_signal_info_ei, "get_signal_info", {}, {}, {}, 0, {}, {}, 0, {} }
#define NAS_SIGNAL_INFO_IND_NEW ({ \
	struct nas_signal_info_ind *ptr = malloc(sizeof(struct nas_signal_info_ind)); \
	ptr->qmi_header->type = 4; ptr->qmi_header->msg_id = 0x0051; \
	ptr->ei = &nas_signal_info_ind_ei; ptr })
#define NAS_SIGNAL_INFO_IND_INITIALIZER { { 4, 0, 0x0051, 0 }, &nas_signal_info_ind_ei, "signal_info_ind", {}, {}, 0, {}, {}, 0 }
#define NAS_GET_LTE_CPHY_CA_INFO_RESP_NEW ({ \
	struct nas_get_lte_cphy_ca_info_resp *ptr = malloc(sizeof(struct nas_get_lte_cphy_ca_info_resp)); \
	ptr->qmi_header->type = 2; ptr->qmi_header->msg_id = 0x00ac; \
	ptr->ei = &nas_get_lte_cphy_ca_info_resp_ei; ptr })
#define NAS_GET_LTE_CPHY_CA_INFO_RESP_INITIALIZER { { 2, 0, 0x00ac, 0 }, &nas_get_lte_cphy_ca_info_resp_ei, "get_lte_cphy_ca_info_resp", {}, 0, {} }

#endif
