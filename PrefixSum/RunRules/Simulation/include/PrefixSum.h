/**\file */
#ifndef SLIC_DECLARATIONS_PrefixSum_H
#define SLIC_DECLARATIONS_PrefixSum_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

int PrefixSum_has_errors(void);
const char* PrefixSum_get_errors(void);


/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] param_length Interface Parameter "length".
 * \param [in] ticks_PrefixSumKernel The number of ticks for which kernel "PrefixSumKernel" will run.
 * \param [in] instream_input The stream should be of size (param_length * 4) bytes.
 * \param [out] outstream_output The stream should be of size (param_length * 4) bytes.
 */
void PrefixSum(
	int64_t param_length,
	uint64_t ticks_PrefixSumKernel,
	const int32_t *instream_input,
	int32_t *outstream_output);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_length Interface Parameter "length".
 * \param [in] ticks_PrefixSumKernel The number of ticks for which kernel "PrefixSumKernel" will run.
 * \param [in] instream_input The stream should be of size (param_length * 4) bytes.
 * \param [out] outstream_output The stream should be of size (param_length * 4) bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *PrefixSum_nonblock(
	int64_t param_length,
	uint64_t ticks_PrefixSumKernel,
	const int32_t *instream_input,
	int32_t *outstream_output);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	int64_t param_length; /**<  [in] Interface Parameter "length". */
	uint64_t ticks_PrefixSumKernel; /**<  [in] The number of ticks for which kernel "PrefixSumKernel" will run. */
	const int32_t *instream_input; /**<  [in] The stream should be of size (param_length * 4) bytes. */
	int32_t *outstream_output; /**<  [out] The stream should be of size (param_length * 4) bytes. */
} PrefixSum_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void PrefixSum_run(
	max_engine_t *engine,
	PrefixSum_actions_t *interface_actions);

/**
 * \brief Advanced static non-blocking function for the interface 'default'.
 *
 * Schedule the actions to run on the engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in] interface_actions Actions to be executed.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *PrefixSum_run_nonblock(
	max_engine_t *engine,
	PrefixSum_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void PrefixSum_run_group(max_group_t *group, PrefixSum_actions_t *interface_actions);

/**
 * \brief Group run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule the actions to run on the first device available in the group and return immediately.
 * The status of the run must be checked with ::max_wait. 
 * Note that use of ::max_nowait is prohibited with non-blocking running on groups:
 * see the ::max_run_group_nonblock documentation for more explanation.
 *
 * \param [in] group Group to use.
 * \param [in] interface_actions Actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *PrefixSum_run_group_nonblock(max_group_t *group, PrefixSum_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void PrefixSum_run_array(max_engarray_t *engarray, PrefixSum_actions_t *interface_actions[]);

/**
 * \brief Array run advanced static non-blocking function for the interface 'default'.
 * 
 *
 * Schedule to run the array of actions on the array of engines, and return immediately.
 * The length of interface_actions must match the size of engarray.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 *
 * \param [in] engarray The array of devices to use.
 * \param [in] interface_actions The array of actions to run.
 * \return A handle on the execution status of the actions, or NULL in case of error.
 */
max_run_t *PrefixSum_run_array_nonblock(max_engarray_t *engarray, PrefixSum_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* PrefixSum_convert(max_file_t *maxfile, PrefixSum_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* PrefixSum_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_PrefixSum_H */

