/*
 *  Copyright (c) 2014 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */
/*
*********************Changed By Rishabh******************************
*/
#include "webrtc/modules/audio_coding/codecs/audio_encoder.h"
#include "webrtc/base/checks.h"

namespace webrtc {

AudioEncoder::EncodedInfo::EncodedInfo() = default;

AudioEncoder::EncodedInfo::~EncodedInfo() = default;

int AudioEncoder::RtpTimestampRateHz() const {
  return SampleRateHz();
}

void AudioEncoder::Encode(uint32_t rtp_timestamp,
                          const int16_t* audio,
                          size_t num_samples_per_channel,
                          size_t max_encoded_bytes,
                          uint8_t* encoded,
                          EncodedInfo* info) {
  CHECK_EQ(num_samples_per_channel,
           static_cast<size_t>(NumChannels() * SampleRateHz() / 100));
  EncodeInternal(rtp_timestamp, audio, max_encoded_bytes, encoded, info);
  CHECK_LE(info->encoded_bytes, max_encoded_bytes);
}

}  // namespace webrtc
