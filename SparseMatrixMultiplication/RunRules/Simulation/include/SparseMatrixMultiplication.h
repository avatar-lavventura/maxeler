/**\file */
#ifndef SLIC_DECLARATIONS_SparseMatrixMultiplication_H
#define SLIC_DECLARATIONS_SparseMatrixMultiplication_H
#include "MaxSLiCInterface.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

int SparseMatrixMultiplication_has_errors(void);
const char* SparseMatrixMultiplication_get_errors(void);
#define SparseMatrixMultiplication_SparseMatrixMultiplicationKernel_watch_stack_trace_isOut ("java.lang.Thread.getStackTrace(Thread.java:1479)/com.maxeler.photon.nodes.NodeWatch.addInput(NodeWatch.java:302)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:136)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:131)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:127)/com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar.watch(DFEVar.java:981)/spmm.SparseMatrixMultiplicationKernel.<init>(SparseMatrixMultiplicationKernel.maxj:66)/spmm.SparseMatrixMultiplicationManager.main(SparseMatrixMultiplicationManager.maxj:15)")
#define SparseMatrixMultiplication_SparseMatrixMultiplicationKernel_watch_stack_trace_flag ("java.lang.Thread.getStackTrace(Thread.java:1479)/com.maxeler.photon.nodes.NodeWatch.addInput(NodeWatch.java:302)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:136)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:131)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:127)/com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar.watch(DFEVar.java:981)/spmm.SparseMatrixMultiplicationKernel.<init>(SparseMatrixMultiplicationKernel.maxj:67)/spmm.SparseMatrixMultiplicationManager.main(SparseMatrixMultiplicationManager.maxj:15)")
#define SparseMatrixMultiplication_SparseMatrixMultiplicationKernel_watch_stack_trace_counter ("java.lang.Thread.getStackTrace(Thread.java:1479)/com.maxeler.photon.nodes.NodeWatch.addInput(NodeWatch.java:302)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:136)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:131)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:127)/com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar.watch(DFEVar.java:981)/spmm.SparseMatrixMultiplicationKernel.<init>(SparseMatrixMultiplicationKernel.maxj:70)/spmm.SparseMatrixMultiplicationManager.main(SparseMatrixMultiplicationManager.maxj:15)")
#define SparseMatrixMultiplication_SparseMatrixMultiplicationKernel_watch_stack_trace_result ("java.lang.Thread.getStackTrace(Thread.java:1479)/com.maxeler.photon.nodes.NodeWatch.addInput(NodeWatch.java:302)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:136)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:131)/com.maxeler.photon.libs.WatchFactory.watch(WatchFactory.java:127)/com.maxeler.maxcompiler.v2.kernelcompiler.types.base.DFEVar.watch(DFEVar.java:981)/spmm.SparseMatrixMultiplicationKernel.<init>(SparseMatrixMultiplicationKernel.maxj:72)/spmm.SparseMatrixMultiplicationManager.main(SparseMatrixMultiplicationManager.maxj:15)")


/*----------------------------------------------------------------------------*/
/*---------------------------- Interface default -----------------------------*/
/*----------------------------------------------------------------------------*/



/**
 * \brief Basic static function for the interface 'default'.
 * 
 * \param [in] param_valSize Interface Parameter "valSize".
 * \param [in] param_vectorSize Interface Parameter "vectorSize".
 * \param [in] instream_FLAG The stream should be of size (param_valSize * 4) bytes.
 * \param [in] instream_INDX The stream should be of size (param_valSize * 4) bytes.
 * \param [in] instream_VAL The stream should be of size (param_valSize * 4) bytes.
 * \param [out] outstream_output The stream should be of size (param_vectorSize * 4) bytes.
 */
void SparseMatrixMultiplication(
	uint32_t param_valSize,
	int32_t param_vectorSize,
	const int32_t *instream_FLAG,
	const uint32_t *instream_INDX,
	const float *instream_VAL,
	float *outstream_output);

/**
 * \brief Basic static non-blocking function for the interface 'default'.
 * 
 * Schedule to run on an engine and return immediately.
 * The status of the run can be checked either by ::max_wait or ::max_nowait;
 * note that one of these *must* be called, so that associated memory can be released.
 * 
 * 
 * \param [in] param_valSize Interface Parameter "valSize".
 * \param [in] param_vectorSize Interface Parameter "vectorSize".
 * \param [in] instream_FLAG The stream should be of size (param_valSize * 4) bytes.
 * \param [in] instream_INDX The stream should be of size (param_valSize * 4) bytes.
 * \param [in] instream_VAL The stream should be of size (param_valSize * 4) bytes.
 * \param [out] outstream_output The stream should be of size (param_vectorSize * 4) bytes.
 * \return A handle on the execution status, or NULL in case of error.
 */
max_run_t *SparseMatrixMultiplication_nonblock(
	uint32_t param_valSize,
	int32_t param_vectorSize,
	const int32_t *instream_FLAG,
	const uint32_t *instream_INDX,
	const float *instream_VAL,
	float *outstream_output);

/**
 * \brief Advanced static interface, structure for the engine interface 'default'
 * 
 */
typedef struct { 
	uint32_t param_valSize; /**<  [in] Interface Parameter "valSize". */
	int32_t param_vectorSize; /**<  [in] Interface Parameter "vectorSize". */
	const int32_t *instream_FLAG; /**<  [in] The stream should be of size (param_valSize * 4) bytes. */
	const uint32_t *instream_INDX; /**<  [in] The stream should be of size (param_valSize * 4) bytes. */
	const float *instream_VAL; /**<  [in] The stream should be of size (param_valSize * 4) bytes. */
	float *outstream_output; /**<  [out] The stream should be of size (param_vectorSize * 4) bytes. */
} SparseMatrixMultiplication_actions_t;

/**
 * \brief Advanced static function for the interface 'default'.
 * 
 * \param [in] engine The engine on which the actions will be executed.
 * \param [in,out] interface_actions Actions to be executed.
 */
void SparseMatrixMultiplication_run(
	max_engine_t *engine,
	SparseMatrixMultiplication_actions_t *interface_actions);

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
max_run_t *SparseMatrixMultiplication_run_nonblock(
	max_engine_t *engine,
	SparseMatrixMultiplication_actions_t *interface_actions);

/**
 * \brief Group run advanced static function for the interface 'default'.
 * 
 * \param [in] group Group to use.
 * \param [in,out] interface_actions Actions to run.
 *
 * Run the actions on the first device available in the group.
 */
void SparseMatrixMultiplication_run_group(max_group_t *group, SparseMatrixMultiplication_actions_t *interface_actions);

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
max_run_t *SparseMatrixMultiplication_run_group_nonblock(max_group_t *group, SparseMatrixMultiplication_actions_t *interface_actions);

/**
 * \brief Array run advanced static function for the interface 'default'.
 * 
 * \param [in] engarray The array of devices to use.
 * \param [in,out] interface_actions The array of actions to run.
 *
 * Run the array of actions on the array of engines.  The length of interface_actions
 * must match the size of engarray.
 */
void SparseMatrixMultiplication_run_array(max_engarray_t *engarray, SparseMatrixMultiplication_actions_t *interface_actions[]);

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
max_run_t *SparseMatrixMultiplication_run_array_nonblock(max_engarray_t *engarray, SparseMatrixMultiplication_actions_t *interface_actions[]);

/**
 * \brief Converts a static-interface action struct into a dynamic-interface max_actions_t struct.
 *
 * Note that this is an internal utility function used by other functions in the static interface.
 *
 * \param [in] maxfile The maxfile to use.
 * \param [in] interface_actions The interface-specific actions to run.
 * \return The dynamic-interface actions to run, or NULL in case of error.
 */
max_actions_t* SparseMatrixMultiplication_convert(max_file_t *maxfile, SparseMatrixMultiplication_actions_t *interface_actions);

/**
 * \brief Initialise a maxfile.
 */
max_file_t* SparseMatrixMultiplication_init(void);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* SLIC_DECLARATIONS_SparseMatrixMultiplication_H */

