
#ifndef __PSPTESTS__EXCEPTION_INFO_H__
#define __PSPTESTS__EXCEPTION_INFO_H__

#include <stdint.h>

#define MAGIC_VAL_1    0xdead
#define MAGIC_VAL_2    0xf1a6
#define MAGIC_VAL_3    0xbaad
#define MAGIC_VAL_4    0xf00d

#define GET_EX_CAUSE(cause)  (((cause) >> 2) & 31)

#define EX_MEM_ADD_LD_ERR      4
#define EX_MEM_ADD_ST_ERR      5
#define EX_MEM_BUS_ERR         7
#define EX_ILLEGAL_INST       10        // An instruction that's not supported

typedef struct {
	uint32_t cause;
	uint32_t status;
	uint32_t badvaddr;

	uint32_t gpr[32];
	uint32_t mlo, mhi;
} cpu_state;

typedef struct {
	uint16_t magic[4];                 // Must be valid for exception capture

	// This must be filled by the user-app to properly capture the exception
	uint32_t armed;                    // Whether we want to capture or not
	uint32_t expected_epc;             // The expected EPC value

	// This is filled by the kernel module with exception-related information
	uint32_t exception_count;
	cpu_state state;
} exception_control_block;


#endif

