/*
 * Copyright (C) 2016  Andrew Gunnerson <andrewgunnerson@gmail.com>
 *
 * This file is part of DualBootPatcher
 *
 * DualBootPatcher is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DualBootPatcher is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DualBootPatcher.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "mbdevice/device.h"

namespace mb
{
namespace device
{

enum class JsonErrorType : uint16_t
{
    // Use |line| and |column| fields
    ParseError = 1,
    // Use |context|, |expected_type|, and |actual_type| fields
    MismatchedType,
    // Use |context| field
    UnknownKey,
    // Use |context] field
    UnknownValue,
};

struct JsonError
{
    JsonErrorType type;

    int line;
    int column;

    std::string context;
    std::string expected_type;
    std::string actual_type;
};

MB_EXPORT bool device_from_json(const std::string &json, Device &device,
                                JsonError &error);

MB_EXPORT bool device_list_from_json(const std::string &json,
                                     std::vector<Device> &devices,
                                     JsonError &error);

MB_EXPORT bool device_to_json(const Device &device, std::string &json);

}
}
