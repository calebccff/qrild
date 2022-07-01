#ifndef __QMI_DMS_H__
#define __QMI_DMS_H__

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define get_next(_type, _sz) ({ \
	void* buf = ptr + len; \
	len += _sz; \
	if (len > buf_sz) goto err_wrong_len; \
	*(_type*)buf; \
})

struct qmi_tlv;

struct qmi_tlv *qmi_tlv_init(unsigned txn, unsigned msg_id, unsigned type);
struct qmi_tlv *qmi_tlv_init_ctl(unsigned txn, unsigned msg_id, unsigned type);
struct qmi_tlv *qmi_tlv_decode(void *buf, size_t len, unsigned *txn, unsigned type);
struct qmi_tlv *qmi_tlv_decode_ctl(void *buf, size_t len, unsigned *txn, unsigned type);
void *qmi_tlv_encode(struct qmi_tlv *tlv, size_t *len);
void *qmi_tlv_encode_ctl(struct qmi_tlv *tlv, size_t *len);
void qmi_tlv_free(struct qmi_tlv *tlv);

void *qmi_tlv_get(struct qmi_tlv *tlv, unsigned id, size_t *len);
void *qmi_tlv_get_array(struct qmi_tlv *tlv, unsigned id, unsigned len_size, size_t *len, size_t *size);
int qmi_tlv_set(struct qmi_tlv *tlv, unsigned id, void *buf, size_t len);
int qmi_tlv_set_array(struct qmi_tlv *tlv, unsigned id, unsigned len_size, void *buf, size_t len, size_t size);

#define QMI_RESULT_SUCCESS 0
#define QMI_RESULT_FAILURE 1
#define QMI_DMS_GET_OPERATING_MODE 45
#define QMI_DMS_SET_OPERATING_MODE 46
#define QMI_DMS_OPERATING_MODE_ONLINE 0
#define QMI_DMS_OPERATING_MODE_LOW_POWER 1
#define QMI_DMS_OPERATING_MODE_FACTORY_TEST 2
#define QMI_DMS_OPERATING_MODE_OFFLINE 3
#define QMI_DMS_OPERATING_MODE_RESET 4
#define QMI_DMS_OPERATING_MODE_SHUTTING_DOWN 5
#define QMI_DMS_OPERATING_MODE_PERSISTENT_LOW_POWER 6
#define QMI_DMS_OPERATING_MODE_MODE_ONLY_LOW_POWER 7
#define QMI_DMS_OPERATING_MODE_UNKNOWN 255

struct dms_qmi_result {
	uint16_t result;
	uint16_t error;
};

struct dms_get_operating_mode_req;
struct dms_get_operating_mode_resp;
struct dms_set_operating_mode_req;
struct dms_set_operating_mode_resp;

/*
 * dms_get_operating_mode_req message
 */
struct dms_get_operating_mode_req *dms_get_operating_mode_req_alloc(unsigned txn);
struct dms_get_operating_mode_req *dms_get_operating_mode_req_parse(void *buf, size_t len, unsigned *txn);
void *dms_get_operating_mode_req_encode(struct dms_get_operating_mode_req *get_operating_mode_req, size_t *len);
void dms_get_operating_mode_req_free(struct dms_get_operating_mode_req *get_operating_mode_req);

/*
 * dms_get_operating_mode_resp message
 */
struct dms_get_operating_mode_resp *dms_get_operating_mode_resp_alloc(unsigned txn);
struct dms_get_operating_mode_resp *dms_get_operating_mode_resp_parse(void *buf, size_t len, unsigned *txn);
void *dms_get_operating_mode_resp_encode(struct dms_get_operating_mode_resp *get_operating_mode_resp, size_t *len);
void dms_get_operating_mode_resp_free(struct dms_get_operating_mode_resp *get_operating_mode_resp);

int dms_get_operating_mode_resp_set_res(struct dms_get_operating_mode_resp *get_operating_mode_resp, struct dms_qmi_result *val);
struct dms_qmi_result *dms_get_operating_mode_resp_get_res(struct dms_get_operating_mode_resp *get_operating_mode_resp);

int dms_get_operating_mode_resp_set_mode(struct dms_get_operating_mode_resp *get_operating_mode_resp, uint8_t val);
int dms_get_operating_mode_resp_get_mode(struct dms_get_operating_mode_resp *get_operating_mode_resp, uint8_t *val);

int dms_get_operating_mode_resp_set_offline_reason(struct dms_get_operating_mode_resp *get_operating_mode_resp, uint16_t val);
int dms_get_operating_mode_resp_get_offline_reason(struct dms_get_operating_mode_resp *get_operating_mode_resp, uint16_t *val);

int dms_get_operating_mode_resp_set_hardware_restricted(struct dms_get_operating_mode_resp *get_operating_mode_resp, uint8_t val);
int dms_get_operating_mode_resp_get_hardware_restricted(struct dms_get_operating_mode_resp *get_operating_mode_resp, uint8_t *val);

/*
 * dms_set_operating_mode_req message
 */
struct dms_set_operating_mode_req *dms_set_operating_mode_req_alloc(unsigned txn);
struct dms_set_operating_mode_req *dms_set_operating_mode_req_parse(void *buf, size_t len, unsigned *txn);
void *dms_set_operating_mode_req_encode(struct dms_set_operating_mode_req *set_operating_mode_req, size_t *len);
void dms_set_operating_mode_req_free(struct dms_set_operating_mode_req *set_operating_mode_req);

int dms_set_operating_mode_req_set_mode(struct dms_set_operating_mode_req *set_operating_mode_req, uint8_t val);
int dms_set_operating_mode_req_get_mode(struct dms_set_operating_mode_req *set_operating_mode_req, uint8_t *val);

/*
 * dms_set_operating_mode_resp message
 */
struct dms_set_operating_mode_resp *dms_set_operating_mode_resp_alloc(unsigned txn);
struct dms_set_operating_mode_resp *dms_set_operating_mode_resp_parse(void *buf, size_t len, unsigned *txn);
void *dms_set_operating_mode_resp_encode(struct dms_set_operating_mode_resp *set_operating_mode_resp, size_t *len);
void dms_set_operating_mode_resp_free(struct dms_set_operating_mode_resp *set_operating_mode_resp);

int dms_set_operating_mode_resp_set_res(struct dms_set_operating_mode_resp *set_operating_mode_resp, struct dms_qmi_result *val);
struct dms_qmi_result *dms_set_operating_mode_resp_get_res(struct dms_set_operating_mode_resp *set_operating_mode_resp);

#ifdef __cplusplus
}
#endif
#endif
