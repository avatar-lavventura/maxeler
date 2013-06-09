/**\file */
#ifndef SLIC_DECLARATIONS_RecurrenceEquation_H
#define SLIC_DECLARATIONS_RecurrenceEquation_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

int RecurrenceEquation_has_errors(void);
const char* RecurrenceEquation_get_errors(void);


/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] param_size Interface Parameter "size".
 * \param [in] param_z0 Interface Parameter "z0".
 * \param [in] param_z1 Interface Parameter "z1".
 * \param [in] instream_a The stream should be of size (param_size * 4) bytes.
 * \param [in] instream_b The stream should be of size (param_size * 4) bytes.
 * \param [out] outstream_z The stream should be of size (param_size * 4) bytes.
 */
void RecurrenceEquation(
	uint64_t param_size,
	int32_t param_z0,
	int32_t param_z1,
	const int32_t *instream_a,
	const int32_t *instream_b,
	int32_t *outstream_z);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_size Interface Parameter "size".
 * \param [in] param_z0 Interface Parameter "z0".
 * \param [in] param_z1 Interface Parameter "z1".
 * \param [in] instream_a The stream should be of size (param_size * 4) bytes.
 * \param [in] instream_b The stream should be of size (param_size * 4) bytes.
 * \param [out] outstream_z The stream should be of size (param_size * 4) bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *RecurrenceEquation_nonblock(
	uint64_t param_size,
	int32_t param_z0,
	int32_t param_z1,
	const int32_t *instream_a,
	const int32_t *instream_b,
	int32_t *outstream_z);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	uint64_t param_size; /**<  [in] Interface Parameter "size". */
	int32_t param_z0; /**<  [in] Interface Parameter "z0". */
	int32_t param_z1; /**<  [in] Interface Parameter "z1". */
	const int32_t *instream_a; /**<  [in] The stream should be of size (param_size * 4) bytes. */
	const int32_t *instream_b; /**<  [in] The stream should be of size (param_size * 4) bytes. */
	int32_t *outstream_z; /**<  [out] The stream should be of size (param_size * 4) bytes. */
} RecurrenceEquation_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void RecurrenceEquation_run(
	max_engine_t *engine,
	RecurrenceEquation_actions_t *interface_actions);

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
max_run_t *RecurrenceEquation_run_nonblock(
	max_engine_t *engine,
	RecurrenceEquation_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void RecurrenceEquation_run_group(max_group_t *group, RecurrenceEquation_actions_t *interface_actions);

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
max_run_t *RecurrenceEquation_run_group_nonblock(max_group_t *group, RecurrenceEquation_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void RecurrenceEquation_run_array(max_engarray_t *engarray, RecurrenceEquation_actions_t *interface_actions[]);

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
max_run_t *RecurrenceEquation_run_array_nonblock(max_engarray_t *engarray, RecurrenceEquation_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* RecurrenceEquation_convert(max_file_t *maxfile, RecurrenceEquation_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* RecurrenceEquation_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_RecurrenceEquation_H */

