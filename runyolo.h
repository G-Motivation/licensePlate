#ifndef RUNYOLO_H
#define RUNYOLO_H
#include "licenseplatedialog.h"
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
namespace runYolo
{
    std::shared_ptr<YOLO> yolo = nullptr;
    std::unique_ptr<licensePlateDialog> w = nullptr;
}

#endif // RUNYOLO_H
