/*
 *  Copyright (c) 2011 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
/********************
Edited by Chaitanya Rajesh
*/
#ifndef WEBRTC_MODULES_AUDIO_CODING_MAIN_INTERFACE_AUDIO_CODING_MODULE_TYPEDEFS_H_
#define WEBRTC_MODULES_AUDIO_CODING_MAIN_INTERFACE_AUDIO_CODING_MODULE_TYPEDEFS_H_

#include <map>

#include "webrtc/modules/interface/module_common_types.h"
#include "webrtc/typedefs.h"

namespace webrtc {

///////////////////////////////////////////////////////////////////////////
// enum AudioPlayoutMode
// An enumerator for different playout modes.
//
// -voice       : This is the standard mode for VoIP calls. The trade-off
//                between low delay and jitter robustness is optimized
//                for high-quality two-way communication.
//                NetEQs packet loss concealment and signal processing
//                capabilities are fully employed.
// -fax         : The fax mode is optimized for decodability of fax signals
//                rather than for perceived audio quality. When this mode
//                is selected, NetEQ will do as few delay changes as possible,
//                trying to maintain a high and constant delay. Meanwhile,
//                the packet loss concealment efforts are reduced.
//
// -streaming   : In the case of one-way communication such as passive
//                conference participant, a webinar, or a streaming application,
//                this mode can be used to improve the jitter robustness at
//                the cost of increased delay.
// -off         : Turns off most of NetEQ's features. Stuffs zeros for lost
//                packets and during buffer increases.
//
enum AudioPlayoutMode {
  voice = 0,
  fax = 1,
  streaming = 2,
  off = 3,
};

///////////////////////////////////////////////////////////////////////////
// enum ACMSpeechType
// An enumerator for possible labels of a decoded frame.
//
// -normal      : a normal speech frame. If VAD is enabled on the
//                incoming stream this label indicate that the
//                frame is active.
// -PLC         : a PLC frame. The corresponding packet was lost
//                and this frame generated by PLC techniques.
// -CNG         : the frame is comfort noise. This happens if VAD
//                is enabled at the sender and we have received
//                SID.
// -PLCCNG      : PLC will fade to comfort noise if the duration
//                of PLC is long. This labels such a case.
// -VADPassive  : the VAD at the receiver recognizes this frame as
//                passive.
//
enum ACMSpeechType {
  normal = 0,
  PLC = 1,
  CNG = 2,
  PLCCNG = 3,
  VADPassive = 4
};

///////////////////////////////////////////////////////////////////////////
// enum ACMVADMode
// An enumerator for aggressiveness of VAD
// -VADNormal                : least aggressive mode.
// -VADLowBitrate            : more aggressive than "VADNormal" to save on
//                             bit-rate.
// -VADAggr                  : an aggressive mode.
// -VADVeryAggr              : the most agressive mode.
//
enum ACMVADMode {
  VADNormal = 0,
  VADLowBitrate = 1,
  VADAggr = 2,
  VADVeryAggr = 3
};

///////////////////////////////////////////////////////////////////////////
// enum ACMCountries
// An enumerator for countries, used when enabling CPT for a specific country.
//
enum ACMCountries {
  ACMDisableCountryDetection = -1, // disable CPT detection
  ACMUSA = 0,
  ACMJapan,
  ACMCanada,
  ACMFrance,
  ACMGermany,
  ACMAustria,
  ACMBelgium,
  ACMUK,
  ACMCzech,
  ACMDenmark,
  ACMFinland,
  ACMGreece,
  ACMHungary,
  ACMIceland,
  ACMIreland,
  ACMItaly,
  ACMLuxembourg,
  ACMMexico,
  ACMNorway,
  ACMPoland,
  ACMPortugal,
  ACMSpain,
  ACMSweden,
  ACMTurkey,
  ACMChina,
  ACMHongkong,
  ACMTaiwan,
  ACMKorea,
  ACMSingapore,
  ACMNonStandard1
// non-standard countries
};

///////////////////////////////////////////////////////////////////////////
// enum ACMAMRPackingFormat
// An enumerator for different bit-packing format of AMR codec according to
// RFC 3267.
//
// -AMRUndefined           : undefined.
// -AMRBandwidthEfficient  : bandwidth-efficient mode.
// -AMROctetAlligned       : Octet-alligned mode.
// -AMRFileStorage         : file-storage mode.
//
enum ACMAMRPackingFormat {
  AMRUndefined = -1,
  AMRBandwidthEfficient = 0,
  AMROctetAlligned = 1,
  AMRFileStorage = 2
};

///////////////////////////////////////////////////////////////////////////
//
// Enumeration of background noise mode a mapping from NetEQ interface.
//
// -On                  : default "normal" behavior with eternal noise
// -Fade                : noise fades to zero after some time
// -Off                 : background noise is always zero
//
enum ACMBackgroundNoiseMode {
  On,
  Fade,
  Off
};

///////////////////////////////////////////////////////////////////////////
//
// Enumeration of Opus mode for intended application.
//
// kVoip              : optimized for voice signals.
// kAudio             : optimized for non-voice signals like music.
//
enum OpusApplicationMode {
 kVoip = 0,
 kAudio = 1,
};

}  // namespace webrtc

#endif  // WEBRTC_MODULES_AUDIO_CODING_MAIN_INTERFACE_AUDIO_CODING_MODULE_TYPEDEFS_H_
