/*
 * Copyright (c) 2019 Elastos Foundation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __TEST_SUITES_H__
#define __TEST_SUITES_H__

#include <CUnit/Basic.h>

typedef CU_SuiteInfo* (*SuiteInfoFunc)(void);

typedef struct TestSuite {
    const char* fileName;
    SuiteInfoFunc getSuiteInfo;
} TestSuite;

#define DECL_TESTSUITE(mod) \
    CU_SuiteInfo* mod##_suite_info(void);

#define DEFINE_TESTSUITE(mod) \
    { \
        .fileName     = #mod".c", \
        .getSuiteInfo = mod##_suite_info \
    }

#define DEFINE_TESTSUITE_NULL \
    { \
        .fileName = NULL, \
        .getSuiteInfo  = NULL\
    }

#include "vctests/suites.h"
#include "didtests/suites.h"
#include "doctests/suites.h"
#include "pubdidtests/suites.h"
#include "dstoretests/suites.h"

TestSuite suites[] = {
    DEFINE_DID_TESTSUITES,
    DEFINE_VC_TESTSUITES,
    DEFINE_DOC_TESTSUITES,
    DEFINE_DSTORE_TESTSUITES,
    DEFINE_PUBDID_TESTSUITES,
    DEFINE_TESTSUITE_NULL
};

#endif /* __TEST_SUITES_H__ */