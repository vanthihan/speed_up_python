#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "pythonsupport.c"
#include "__native.h"
#include "__native_internal.h"
static PyMethodDef module_methods[] = {
    {"lcs", (PyCFunction)CPyPy_lcs, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "lcs_with_mypyc",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_lcs_with_mypyc(void)
{
    PyObject* modname = NULL;
    if (CPyModule_lcs_with_mypyc_internal) {
        Py_INCREF(CPyModule_lcs_with_mypyc_internal);
        return CPyModule_lcs_with_mypyc_internal;
    }
    CPyModule_lcs_with_mypyc_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_lcs_with_mypyc_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_lcs_with_mypyc_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_lcs_with_mypyc_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_lcs_with_mypyc_internal;
    fail:
    Py_CLEAR(CPyModule_lcs_with_mypyc_internal);
    Py_CLEAR(modname);
    return NULL;
}

CPyTagged CPyDef_lcs(PyObject *cpy_r_X, PyObject *cpy_r_Y) {
    int64_t cpy_r_r0;
    char cpy_r_r1;
    CPyTagged cpy_r_r2;
    CPyTagged cpy_r_m;
    int64_t cpy_r_r3;
    char cpy_r_r4;
    CPyTagged cpy_r_r5;
    CPyTagged cpy_r_n;
    PyObject *cpy_r_r6;
    CPyTagged cpy_r_r7;
    CPyTagged cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r__;
    int64_t cpy_r_r10;
    char cpy_r_r11;
    int64_t cpy_r_r12;
    char cpy_r_r13;
    char cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    CPyPtr cpy_r_r18;
    CPyPtr cpy_r_r19;
    CPyTagged cpy_r_r20;
    PyObject *cpy_r_r21;
    int32_t cpy_r_r22;
    char cpy_r_r23;
    CPyTagged cpy_r_r24;
    PyObject *cpy_r_r25;
    CPyTagged cpy_r_r26;
    CPyTagged cpy_r_r27;
    CPyTagged cpy_r_i;
    int64_t cpy_r_r28;
    char cpy_r_r29;
    int64_t cpy_r_r30;
    char cpy_r_r31;
    char cpy_r_r32;
    char cpy_r_r33;
    CPyTagged cpy_r_r34;
    CPyTagged cpy_r_r35;
    CPyTagged cpy_r_j;
    int64_t cpy_r_r36;
    char cpy_r_r37;
    int64_t cpy_r_r38;
    char cpy_r_r39;
    char cpy_r_r40;
    char cpy_r_r41;
    CPyTagged cpy_r_r42;
    PyObject *cpy_r_r43;
    CPyTagged cpy_r_r44;
    PyObject *cpy_r_r45;
    int32_t cpy_r_r46;
    char cpy_r_r47;
    PyObject *cpy_r_r48;
    char cpy_r_r49;
    char cpy_r_r50;
    char cpy_r_r51;
    CPyTagged cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject *cpy_r_r54;
    CPyTagged cpy_r_r55;
    PyObject *cpy_r_r56;
    CPyTagged cpy_r_r57;
    CPyTagged cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    char cpy_r_r62;
    CPyTagged cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    CPyTagged cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    CPyTagged cpy_r_r70;
    PyObject *cpy_r_r71;
    CPyTagged cpy_r_r72;
    int64_t cpy_r_r73;
    char cpy_r_r74;
    int64_t cpy_r_r75;
    char cpy_r_r76;
    char cpy_r_r77;
    char cpy_r_r78;
    CPyTagged cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    char cpy_r_r83;
    CPyTagged cpy_r_r84;
    CPyTagged cpy_r_r85;
    PyObject *cpy_r_r86;
    PyObject *cpy_r_r87;
    PyObject *cpy_r_r88;
    CPyTagged cpy_r_r89;
    CPyTagged cpy_r_r90;
    cpy_r_r0 = CPyStr_Size_size_t(cpy_r_X);
    cpy_r_r1 = cpy_r_r0 >= 0;
    if (unlikely(!cpy_r_r1)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 5, CPyStatic_globals);
        goto CPyL59;
    }
    cpy_r_r2 = cpy_r_r0 << 1;
    cpy_r_m = cpy_r_r2;
    cpy_r_r3 = CPyStr_Size_size_t(cpy_r_Y);
    cpy_r_r4 = cpy_r_r3 >= 0;
    if (unlikely(!cpy_r_r4)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 6, CPyStatic_globals);
        goto CPyL60;
    }
    cpy_r_r5 = cpy_r_r3 << 1;
    cpy_r_n = cpy_r_r5;
    cpy_r_r6 = PyList_New(0);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 7, CPyStatic_globals);
        goto CPyL61;
    }
    cpy_r_r7 = CPyTagged_Add(cpy_r_m, 2);
    cpy_r_r8 = 0;
    CPyTagged_INCREF(cpy_r_r8);
    cpy_r_r9 = CPyTagged_StealAsObject(cpy_r_r8);
    cpy_r__ = cpy_r_r9;
    CPy_DECREF(cpy_r__);
CPyL4: ;
    cpy_r_r10 = cpy_r_r8 & 1;
    cpy_r_r11 = cpy_r_r10 != 0;
    if (cpy_r_r11) goto CPyL6;
    cpy_r_r12 = cpy_r_r7 & 1;
    cpy_r_r13 = cpy_r_r12 != 0;
    if (!cpy_r_r13) goto CPyL7;
CPyL6: ;
    cpy_r_r14 = CPyTagged_IsLt_(cpy_r_r8, cpy_r_r7);
    if (cpy_r_r14) {
        goto CPyL8;
    } else
        goto CPyL62;
CPyL7: ;
    cpy_r_r15 = (Py_ssize_t)cpy_r_r8 < (Py_ssize_t)cpy_r_r7;
    if (!cpy_r_r15) goto CPyL62;
CPyL8: ;
    cpy_r_r16 = PyList_New(1);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 7, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r17 = CPyStatics[9]; /* 0 */
    cpy_r_r18 = (CPyPtr)&((PyListObject *)cpy_r_r16)->ob_item;
    cpy_r_r19 = *(CPyPtr *)cpy_r_r18;
    CPy_INCREF(cpy_r_r17);
    *(PyObject * *)cpy_r_r19 = cpy_r_r17;
    cpy_r_r20 = CPyTagged_Add(cpy_r_n, 2);
    cpy_r_r21 = CPySequence_Multiply(cpy_r_r16, cpy_r_r20);
    CPy_DECREF(cpy_r_r16);
    CPyTagged_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 7, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r22 = PyList_Append(cpy_r_r6, cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    cpy_r_r23 = cpy_r_r22 >= 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 7, CPyStatic_globals);
        goto CPyL63;
    }
    cpy_r_r24 = CPyTagged_Add(cpy_r_r8, 2);
    CPyTagged_DECREF(cpy_r_r8);
    CPyTagged_INCREF(cpy_r_r24);
    cpy_r_r8 = cpy_r_r24;
    cpy_r_r25 = CPyTagged_StealAsObject(cpy_r_r24);
    cpy_r__ = cpy_r_r25;
    CPy_DECREF(cpy_r__);
    goto CPyL4;
CPyL12: ;
    cpy_r_r26 = CPyTagged_Add(cpy_r_m, 2);
    cpy_r_r27 = 2;
    CPyTagged_INCREF(cpy_r_r27);
    cpy_r_i = cpy_r_r27;
CPyL13: ;
    cpy_r_r28 = cpy_r_r27 & 1;
    cpy_r_r29 = cpy_r_r28 != 0;
    if (cpy_r_r29) goto CPyL15;
    cpy_r_r30 = cpy_r_r26 & 1;
    cpy_r_r31 = cpy_r_r30 != 0;
    if (!cpy_r_r31) goto CPyL16;
CPyL15: ;
    cpy_r_r32 = CPyTagged_IsLt_(cpy_r_r27, cpy_r_r26);
    if (cpy_r_r32) {
        goto CPyL17;
    } else
        goto CPyL64;
CPyL16: ;
    cpy_r_r33 = (Py_ssize_t)cpy_r_r27 < (Py_ssize_t)cpy_r_r26;
    if (!cpy_r_r33) goto CPyL64;
CPyL17: ;
    cpy_r_r34 = CPyTagged_Add(cpy_r_n, 2);
    cpy_r_r35 = 2;
    CPyTagged_INCREF(cpy_r_r35);
    cpy_r_j = cpy_r_r35;
CPyL18: ;
    cpy_r_r36 = cpy_r_r35 & 1;
    cpy_r_r37 = cpy_r_r36 != 0;
    if (cpy_r_r37) goto CPyL20;
    cpy_r_r38 = cpy_r_r34 & 1;
    cpy_r_r39 = cpy_r_r38 != 0;
    if (!cpy_r_r39) goto CPyL21;
CPyL20: ;
    cpy_r_r40 = CPyTagged_IsLt_(cpy_r_r35, cpy_r_r34);
    if (cpy_r_r40) {
        goto CPyL22;
    } else
        goto CPyL65;
CPyL21: ;
    cpy_r_r41 = (Py_ssize_t)cpy_r_r35 < (Py_ssize_t)cpy_r_r34;
    if (!cpy_r_r41) goto CPyL65;
CPyL22: ;
    cpy_r_r42 = CPyTagged_Subtract(cpy_r_i, 2);
    cpy_r_r43 = CPyStr_GetItem(cpy_r_X, cpy_r_r42);
    CPyTagged_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r43 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 11, CPyStatic_globals);
        goto CPyL66;
    }
    cpy_r_r44 = CPyTagged_Subtract(cpy_r_j, 2);
    cpy_r_r45 = CPyStr_GetItem(cpy_r_Y, cpy_r_r44);
    CPyTagged_DECREF(cpy_r_r44);
    if (unlikely(cpy_r_r45 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 11, CPyStatic_globals);
        goto CPyL67;
    }
    cpy_r_r46 = PyUnicode_Compare(cpy_r_r43, cpy_r_r45);
    CPy_DECREF(cpy_r_r43);
    CPy_DECREF(cpy_r_r45);
    cpy_r_r47 = cpy_r_r46 == -1;
    if (!cpy_r_r47) goto CPyL27;
    cpy_r_r48 = PyErr_Occurred();
    cpy_r_r49 = cpy_r_r48 != NULL;
    if (!cpy_r_r49) goto CPyL27;
    cpy_r_r50 = CPy_KeepPropagating();
    if (unlikely(!cpy_r_r50)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 11, CPyStatic_globals);
        goto CPyL66;
    }
CPyL27: ;
    cpy_r_r51 = cpy_r_r46 == 0;
    if (!cpy_r_r51) goto CPyL35;
    cpy_r_r52 = CPyTagged_Subtract(cpy_r_i, 2);
    cpy_r_r53 = CPyList_GetItem(cpy_r_r6, cpy_r_r52);
    CPyTagged_DECREF(cpy_r_r52);
    if (unlikely(cpy_r_r53 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 12, CPyStatic_globals);
        goto CPyL66;
    }
    if (likely(PyList_Check(cpy_r_r53)))
        cpy_r_r54 = cpy_r_r53;
    else {
        CPy_TypeErrorTraceback("lcs_with_mypyc.py", "lcs", 12, CPyStatic_globals, "list", cpy_r_r53);
        goto CPyL66;
    }
    cpy_r_r55 = CPyTagged_Subtract(cpy_r_j, 2);
    cpy_r_r56 = CPyList_GetItemBorrow(cpy_r_r54, cpy_r_r55);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 12, CPyStatic_globals);
        goto CPyL68;
    }
    if (likely(PyLong_Check(cpy_r_r56)))
        cpy_r_r57 = CPyTagged_FromObject(cpy_r_r56);
    else {
        CPy_TypeError("int", cpy_r_r56); cpy_r_r57 = CPY_INT_TAG;
    }
    if (unlikely(cpy_r_r57 == CPY_INT_TAG)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 12, CPyStatic_globals);
        goto CPyL68;
    }
    cpy_r_r58 = CPyTagged_Add(cpy_r_r57, 2);
    CPyTagged_DECREF(cpy_r_r57);
    CPy_DECREF(cpy_r_r54);
    CPyTagged_DECREF(cpy_r_r55);
    cpy_r_r59 = CPyList_GetItem(cpy_r_r6, cpy_r_i);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 12, CPyStatic_globals);
        goto CPyL69;
    }
    if (likely(PyList_Check(cpy_r_r59)))
        cpy_r_r60 = cpy_r_r59;
    else {
        CPy_TypeErrorTraceback("lcs_with_mypyc.py", "lcs", 12, CPyStatic_globals, "list", cpy_r_r59);
        goto CPyL69;
    }
    cpy_r_r61 = CPyTagged_StealAsObject(cpy_r_r58);
    cpy_r_r62 = CPyList_SetItem(cpy_r_r60, cpy_r_j, cpy_r_r61);
    CPy_DECREF(cpy_r_r60);
    CPyTagged_DECREF(cpy_r_j);
    if (unlikely(!cpy_r_r62)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 12, CPyStatic_globals);
        goto CPyL70;
    } else
        goto CPyL52;
CPyL35: ;
    cpy_r_r63 = CPyTagged_Subtract(cpy_r_i, 2);
    cpy_r_r64 = CPyList_GetItemBorrow(cpy_r_r6, cpy_r_r63);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals);
        goto CPyL71;
    }
    if (likely(PyList_Check(cpy_r_r64)))
        cpy_r_r65 = cpy_r_r64;
    else {
        CPy_TypeErrorTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals, "list", cpy_r_r64);
        goto CPyL71;
    }
    cpy_r_r66 = CPyList_GetItem(cpy_r_r65, cpy_r_j);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals);
        goto CPyL71;
    }
    if (likely(PyLong_Check(cpy_r_r66)))
        cpy_r_r67 = CPyTagged_FromObject(cpy_r_r66);
    else {
        CPy_TypeError("int", cpy_r_r66); cpy_r_r67 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r66);
    if (unlikely(cpy_r_r67 == CPY_INT_TAG)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals);
        goto CPyL71;
    }
    CPyTagged_DECREF(cpy_r_r63);
    cpy_r_r68 = CPyList_GetItem(cpy_r_r6, cpy_r_i);
    if (unlikely(cpy_r_r68 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals);
        goto CPyL72;
    }
    if (likely(PyList_Check(cpy_r_r68)))
        cpy_r_r69 = cpy_r_r68;
    else {
        CPy_TypeErrorTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals, "list", cpy_r_r68);
        goto CPyL72;
    }
    cpy_r_r70 = CPyTagged_Subtract(cpy_r_j, 2);
    cpy_r_r71 = CPyList_GetItem(cpy_r_r69, cpy_r_r70);
    CPy_DECREF(cpy_r_r69);
    CPyTagged_DECREF(cpy_r_r70);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals);
        goto CPyL72;
    }
    if (likely(PyLong_Check(cpy_r_r71)))
        cpy_r_r72 = CPyTagged_FromObject(cpy_r_r71);
    else {
        CPy_TypeError("int", cpy_r_r71); cpy_r_r72 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r71);
    if (unlikely(cpy_r_r72 == CPY_INT_TAG)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals);
        goto CPyL72;
    }
    cpy_r_r73 = cpy_r_r72 & 1;
    cpy_r_r74 = cpy_r_r73 != 0;
    if (cpy_r_r74) goto CPyL45;
    cpy_r_r75 = cpy_r_r67 & 1;
    cpy_r_r76 = cpy_r_r75 != 0;
    if (!cpy_r_r76) goto CPyL46;
CPyL45: ;
    cpy_r_r77 = CPyTagged_IsLt_(cpy_r_r67, cpy_r_r72);
    if (cpy_r_r77) {
        goto CPyL73;
    } else
        goto CPyL74;
CPyL46: ;
    cpy_r_r78 = (Py_ssize_t)cpy_r_r72 > (Py_ssize_t)cpy_r_r67;
    if (cpy_r_r78) {
        goto CPyL73;
    } else
        goto CPyL74;
CPyL47: ;
    cpy_r_r79 = cpy_r_r72;
    goto CPyL49;
CPyL48: ;
    cpy_r_r79 = cpy_r_r67;
CPyL49: ;
    cpy_r_r80 = CPyList_GetItem(cpy_r_r6, cpy_r_i);
    if (unlikely(cpy_r_r80 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals);
        goto CPyL75;
    }
    if (likely(PyList_Check(cpy_r_r80)))
        cpy_r_r81 = cpy_r_r80;
    else {
        CPy_TypeErrorTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals, "list", cpy_r_r80);
        goto CPyL75;
    }
    cpy_r_r82 = CPyTagged_StealAsObject(cpy_r_r79);
    cpy_r_r83 = CPyList_SetItem(cpy_r_r81, cpy_r_j, cpy_r_r82);
    CPy_DECREF(cpy_r_r81);
    CPyTagged_DECREF(cpy_r_j);
    if (unlikely(!cpy_r_r83)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 14, CPyStatic_globals);
        goto CPyL70;
    }
CPyL52: ;
    cpy_r_r84 = CPyTagged_Add(cpy_r_r35, 2);
    CPyTagged_DECREF(cpy_r_r35);
    CPyTagged_INCREF(cpy_r_r84);
    cpy_r_r35 = cpy_r_r84;
    cpy_r_j = cpy_r_r84;
    goto CPyL18;
CPyL53: ;
    cpy_r_r85 = CPyTagged_Add(cpy_r_r27, 2);
    CPyTagged_DECREF(cpy_r_r27);
    CPyTagged_INCREF(cpy_r_r85);
    cpy_r_r27 = cpy_r_r85;
    cpy_r_i = cpy_r_r85;
    goto CPyL13;
CPyL54: ;
    cpy_r_r86 = CPyList_GetItemBorrow(cpy_r_r6, cpy_r_m);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 16, CPyStatic_globals);
        goto CPyL76;
    }
    if (likely(PyList_Check(cpy_r_r86)))
        cpy_r_r87 = cpy_r_r86;
    else {
        CPy_TypeErrorTraceback("lcs_with_mypyc.py", "lcs", 16, CPyStatic_globals, "list", cpy_r_r86);
        goto CPyL76;
    }
    cpy_r_r88 = CPyList_GetItem(cpy_r_r87, cpy_r_n);
    CPyTagged_DECREF(cpy_r_n);
    if (unlikely(cpy_r_r88 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 16, CPyStatic_globals);
        goto CPyL77;
    }
    if (likely(PyLong_Check(cpy_r_r88)))
        cpy_r_r89 = CPyTagged_FromObject(cpy_r_r88);
    else {
        CPy_TypeError("int", cpy_r_r88); cpy_r_r89 = CPY_INT_TAG;
    }
    CPy_DECREF(cpy_r_r88);
    if (unlikely(cpy_r_r89 == CPY_INT_TAG)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 16, CPyStatic_globals);
        goto CPyL77;
    }
    CPy_DECREF(cpy_r_r6);
    CPyTagged_DECREF(cpy_r_m);
    return cpy_r_r89;
CPyL59: ;
    cpy_r_r90 = CPY_INT_TAG;
    return cpy_r_r90;
CPyL60: ;
    CPyTagged_DecRef(cpy_r_m);
    goto CPyL59;
CPyL61: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    goto CPyL59;
CPyL62: ;
    CPyTagged_DECREF(cpy_r_r7);
    CPyTagged_DECREF(cpy_r_r8);
    goto CPyL12;
CPyL63: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r7);
    CPyTagged_DecRef(cpy_r_r8);
    goto CPyL59;
CPyL64: ;
    CPyTagged_DECREF(cpy_r_r26);
    CPyTagged_DECREF(cpy_r_r27);
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL54;
CPyL65: ;
    CPyTagged_DECREF(cpy_r_i);
    CPyTagged_DECREF(cpy_r_r34);
    CPyTagged_DECREF(cpy_r_r35);
    CPyTagged_DECREF(cpy_r_j);
    goto CPyL53;
CPyL66: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r26);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    goto CPyL59;
CPyL67: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r26);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r43);
    goto CPyL59;
CPyL68: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r26);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPy_DecRef(cpy_r_r54);
    CPyTagged_DecRef(cpy_r_r55);
    goto CPyL59;
CPyL69: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r26);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r58);
    goto CPyL59;
CPyL70: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r26);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    goto CPyL59;
CPyL71: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r26);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r63);
    goto CPyL59;
CPyL72: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r26);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r67);
    goto CPyL59;
CPyL73: ;
    CPyTagged_DECREF(cpy_r_r67);
    goto CPyL47;
CPyL74: ;
    CPyTagged_DECREF(cpy_r_r72);
    goto CPyL48;
CPyL75: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    CPy_DecRef(cpy_r_r6);
    CPyTagged_DecRef(cpy_r_r26);
    CPyTagged_DecRef(cpy_r_r27);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_r34);
    CPyTagged_DecRef(cpy_r_r35);
    CPyTagged_DecRef(cpy_r_j);
    CPyTagged_DecRef(cpy_r_r79);
    goto CPyL59;
CPyL76: ;
    CPyTagged_DecRef(cpy_r_m);
    CPyTagged_DecRef(cpy_r_n);
    CPy_DecRef(cpy_r_r6);
    goto CPyL59;
CPyL77: ;
    CPyTagged_DecRef(cpy_r_m);
    CPy_DecRef(cpy_r_r6);
    goto CPyL59;
}

PyObject *CPyPy_lcs(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"X", "Y", 0};
    static CPyArg_Parser parser = {"OO:lcs", kwlist, 0};
    PyObject *obj_X;
    PyObject *obj_Y;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_X, &obj_Y)) {
        return NULL;
    }
    PyObject *arg_X;
    if (likely(PyUnicode_Check(obj_X)))
        arg_X = obj_X;
    else {
        CPy_TypeError("str", obj_X); 
        goto fail;
    }
    PyObject *arg_Y;
    if (likely(PyUnicode_Check(obj_Y)))
        arg_Y = obj_Y;
    else {
        CPy_TypeError("str", obj_Y); 
        goto fail;
    }
    CPyTagged retval = CPyDef_lcs(arg_X, arg_Y);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("lcs_with_mypyc.py", "lcs", 4, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r5;
    void *cpy_r_r7;
    void *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    char cpy_r_r19;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[3]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "<module>", -1, CPyStatic_globals);
        goto CPyL6;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = (PyObject **)&CPyModule_time;
    PyObject **cpy_r_r6[1] = {cpy_r_r5};
    cpy_r_r7 = (void *)&cpy_r_r6;
    int64_t cpy_r_r8[1] = {1};
    cpy_r_r9 = (void *)&cpy_r_r8;
    cpy_r_r10 = CPyStatics[11]; /* (('time', 'time', 'time'),) */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyStatics[5]; /* 'lcs_with_mypyc.py' */
    cpy_r_r13 = CPyStatics[6]; /* '<module>' */
    cpy_r_r14 = CPyImport_ImportMany(cpy_r_r10, cpy_r_r7, cpy_r_r11, cpy_r_r12, cpy_r_r13, cpy_r_r9);
    if (!cpy_r_r14) goto CPyL6;
    cpy_r_r15 = CPyStatics[12]; /* ('List',) */
    cpy_r_r16 = CPyStatics[8]; /* 'typing' */
    cpy_r_r17 = CPyStatic_globals;
    cpy_r_r18 = CPyImport_ImportFromMany(cpy_r_r16, cpy_r_r15, cpy_r_r15, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("lcs_with_mypyc.py", "<module>", 2, CPyStatic_globals);
        goto CPyL6;
    }
    CPyModule_typing = cpy_r_r18;
    CPy_INCREF(CPyModule_typing);
    CPy_DECREF(cpy_r_r18);
    return 1;
CPyL6: ;
    cpy_r_r19 = 2;
    return cpy_r_r19;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_lcs_with_mypyc = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_time = Py_None;
    CPyModule_typing = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[13];
const char * const CPyLit_Str[] = {
    "\006\bbuiltins\004time\021lcs_with_mypyc.py\b<module>\004List\006typing",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0010",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {3, 3, 4, 4, 4, 1, 10, 1, 7};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_lcs_with_mypyc_internal = NULL;
CPyModule *CPyModule_lcs_with_mypyc;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_time;
CPyModule *CPyModule_typing;
CPyTagged CPyDef_lcs(PyObject *cpy_r_X, PyObject *cpy_r_Y);
PyObject *CPyPy_lcs(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
