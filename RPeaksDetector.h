#pragma once
#include "modulesinterfaces.h"

/**
 * Class RPeaksDetector provides set of method to detect R peaks in ECG signal.
 * @class RPeaksDetector
 */
class RPeaksDetector : public RPeaksModule
{
public:

	RPeaksDetector();
	~RPeaksDetector();

	void runModule(const ECGSignal &, ECGRs &);
	void setParams(ParametersTypes &);

  /**
  *  Check R peaks detection status
  *  @return true if detection is finisched
  */
  bool areRsDetected();

  /**
  *  Set new filtered method
  *  @param detectionMethod detection method
  */
  void setDetectionMethod(R_PEAKS_DETECTION_METHOD detectionMethod);

  /**
  *  Get current filtered method
  *  @return filtered method
  */
  R_PEAKS_DETECTION_METHOD getDetectionMethod();

  /**
  *  Execute R peaks detection
  *  @return false if detection cannot be executed
  *  @return true if detection is complete
  */
  bool detectRPeaks();

private:
  /**
  *  Information about detection status
  */
  bool rsDetected;

  /**
  *  Filtered signal from 'ECG_BASALINE'
  */
  ECGSignal filteredSignal;

  /**
  *  R peaks vector
  */
  ECGRs rsPositions;

  /**
  *  R peaks detection method
  */
  R_PEAKS_DETECTION_METHOD detectionMethod;

  /**
  *  PanTompkins R peaks method detection
  *  @param pointer to ECG signal
  */
  void panTompkinsRPeaksDetection(ECGSignal *signal);
  
  /**
  *  Hilbert R peaks method detection
  *  @param pointer to ECG signal
  */
  void hilbertRPeaksDetection(ECGSignal *signal);
};
