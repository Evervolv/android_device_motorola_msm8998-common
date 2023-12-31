/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/strings.h>

#include "KeyDisabler.h"

namespace vendor {
namespace evervolv {
namespace touch {
namespace V1_0 {
namespace implementation {

KeyDisabler::KeyDisabler() {
    mHasKeyDisabler = false;

    mFingerprintNavigation = IFingerprintNavigation::getService();
    if (mFingerprintNavigation != nullptr)
        mHasKeyDisabler = true;
}

// Methods from ::vendor::evervolv::touch::V1_0::IKeyDisabler follow.
Return<bool> KeyDisabler::isEnabled() {
    if (!mHasKeyDisabler) return false;

    return mFingerprintNavigation->isEnabled();
}

Return<bool> KeyDisabler::setEnabled(bool enabled) {
    if (!mHasKeyDisabler) return false;

    mFingerprintNavigation->setNavigation(!enabled);
    return true;
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace touch
}  // namespace evervolv
}  // namespace vendor
