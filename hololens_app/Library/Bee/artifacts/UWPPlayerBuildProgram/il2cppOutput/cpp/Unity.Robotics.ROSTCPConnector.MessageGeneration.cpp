#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename T1, typename T2, typename T3>
struct VirtualActionInvoker3
{
	typedef void (*Action)(void*, T1, T2, T3, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, p2, p3, invokeData.method);
	}
};
template <typename R, typename T1>
struct VirtualFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R, typename T1, typename T2, typename T3>
struct VirtualFuncInvoker3
{
	typedef R (*Func)(void*, T1, T2, T3, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, p3, invokeData.method);
	}
};

struct Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54;
struct Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA;
struct Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2;
struct Func_2_t0B9AE122B87C6F7B2A9654A7B4BD357367C9BD61;
struct IEnumerable_1_t21E2C2093877744709873DDCB2D3C8297821E513;
struct IEnumerable_1_tF95C9E01A913DD50575531C8305932628663D9E9;
struct IEqualityComparer_1_tAE94C8F24AD5B94D4EE85CA9FC59E3409D41CAF7;
struct KeyCollection_t909EF6A32DBCF06256C5355994E42A862EF01855;
struct List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4;
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
struct ValueCollection_t2C1F0CEA83A34BC065556E04218B28AC9C817A40;
struct Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51;
struct EntryU5BU5D_tAE5F05A8A738A615F5B69A97CCC7AA36B2E9F294;
struct ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE;
struct Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D;
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913;
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83;
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA;
struct UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299;
struct CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2;
struct DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293;
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF;
struct MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF;
struct MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7;
struct MethodInfo_t;
struct NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct SemaphoreSlim_t0D5CB5685D9BFA5BF95CEC6E7395490F933E8DB2;
struct Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE;
struct String_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct ReadWriteTask_t0821BF49EE38596C7734E86E1A6A39D769BE2C05;

IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteralAA85FF4E5A7BD42CAFF8E40C42EF0FDF21AF42E2;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_mDE955F76E376B593C215D78CBD1C4F2A40E60B58_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_mCDDC850B62D20A7AAD5DF974538393AB3A43461F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m5A8036FD044CA17B6B9F11640135700F7061BFE4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_m4B63F6735596A1CA8F6EEA0E6C630CACC3F3900E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Clear_m1E9869035CC36C3F683625D97F571B07ECCE756F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_GetEnumerator_m7C61C1682B2BDC2599320E9B76B12AD7F6E2020D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m08520634E23EA7BF64AB1B3F668355EEBA35CE2E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m8070151BA99349188C9F1457EC394480BE0D4ED4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_m88FEB2D94E35C258B61F53400F7CA20E99A7DAD3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_set_Item_mE7F925D8AE61B8675A9B04FC14219B71ED5E1F16_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Message_SerializeTo_mC64C939239BACD2E5C07AF751A3F623CAD42DA3A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Message_get_RosMessageName_m14E754F6CF15594CD26BD56211D3853D15A2D050_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51;
struct ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE;
struct Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913;
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83;
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA;
struct UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CModuleU3E_t6675E429C3816EFFEB3537C181640A4066CC13DA 
{
};
struct Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_tAE5F05A8A738A615F5B69A97CCC7AA36B2E9F294* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_t909EF6A32DBCF06256C5355994E42A862EF01855* ____keys;
	ValueCollection_t2C1F0CEA83A34BC065556E04218B28AC9C817A40* ____values;
	RuntimeObject* ____syncRoot;
};
struct List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4  : public RuntimeObject
{
	ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095  : public RuntimeObject
{
	int32_t ___m_codePage;
	CodePageDataItem_t52460FA30AE37F4F26ACB81055E58002262F19F2* ___dataItem;
	bool ___m_deserializedFromEverett;
	bool ___m_isReadOnly;
	EncoderFallback_tD2C40CE114AA9D8E1F7196608B2D088548015293* ___encoderFallback;
	DecoderFallback_t7324102215E4ED41EC065C02EB501CB0BC23CD90* ___decoderFallback;
};
struct MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE  : public RuntimeObject
{
	RuntimeObject* ____identity;
};
struct MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE_marshaled_pinvoke
{
	Il2CppIUnknown* ____identity;
};
struct MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE_marshaled_com
{
	Il2CppIUnknown* ____identity;
};
struct Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF  : public RuntimeObject
{
};
struct MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF  : public RuntimeObject
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___data;
	int32_t ___offset;
};
struct MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC  : public RuntimeObject
{
};
struct MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7  : public RuntimeObject
{
	int32_t ___m_AlignmentOffset;
	int32_t ___m_LengthCorrection;
	List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* ___m_ListOfSerializations;
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC 
{
	List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* ____list;
	int32_t ____index;
	int32_t ____version;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ____current;
};
struct Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A 
{
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ____list;
	int32_t ____index;
	int32_t ____version;
	RuntimeObject* ____current;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	double ___m_value;
};
struct Int16_tB8EF286A9C33492FA6E6D6E67320BE93E794A175 
{
	int16_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct Int64_t092CFB123BE63C28ACDAF65C68F21A526050DBA3 
{
	int64_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct SByte_tFEFFEF5D2FEBF5207950AE6FAC150FC53B668DB5 
{
	int8_t ___m_value;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE  : public MarshalByRefObject_t8C2F4C5854177FD60439EB1FCCFC1B3CFAFE8DCE
{
	ReadWriteTask_t0821BF49EE38596C7734E86E1A6A39D769BE2C05* ____activeReadWriteTask;
	SemaphoreSlim_t0D5CB5685D9BFA5BF95CEC6E7395490F933E8DB2* ____asyncActiveSemaphore;
};
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	uint16_t ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct UInt64_t8F12534CC8FC4B5860F2A2CD1EE79D322E7A41AF 
{
	uint64_t ___m_value;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct Delegate_t  : public RuntimeObject
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	RuntimeObject* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	bool ___method_is_virtual;
};
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr;
	intptr_t ___invoke_impl;
	Il2CppIUnknown* ___m_target;
	intptr_t ___method;
	intptr_t ___delegate_trampoline;
	intptr_t ___extra_arg;
	intptr_t ___method_code;
	intptr_t ___interp_method;
	intptr_t ___interp_invoke_impl;
	MethodInfo_t* ___method_info;
	MethodInfo_t* ___original_method_info;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data;
	int32_t ___method_is_virtual;
};
struct Exception_t  : public RuntimeObject
{
	String_t* ____className;
	String_t* ____message;
	RuntimeObject* ____data;
	Exception_t* ____innerException;
	String_t* ____helpURL;
	RuntimeObject* ____stackTrace;
	String_t* ____stackTraceString;
	String_t* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	RuntimeObject* ____dynamicMethods;
	int32_t ____HResult;
	String_t* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_pinvoke
{
	char* ____className;
	char* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_pinvoke* ____innerException;
	char* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	char* ____stackTraceString;
	char* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	char* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className;
	Il2CppChar* ____message;
	RuntimeObject* ____data;
	Exception_t_marshaled_com* ____innerException;
	Il2CppChar* ____helpURL;
	Il2CppIUnknown* ____stackTrace;
	Il2CppChar* ____stackTraceString;
	Il2CppChar* ____remoteStackTraceString;
	int32_t ____remoteStackIndex;
	Il2CppIUnknown* ____dynamicMethods;
	int32_t ____HResult;
	Il2CppChar* ____source;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces;
	Il2CppSafeArray* ___native_trace_ips;
	int32_t ___caught_in_unmanaged;
};
struct MulticastDelegate_t  : public Delegate_t
{
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates;
};
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates;
};
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates;
};
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct Func_2_t0B9AE122B87C6F7B2A9654A7B4BD357367C9BD61  : public MulticastDelegate_t
{
};
struct NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4_StaticFields
{
	ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* ___s_emptyArray;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray;
};
struct Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095_StaticFields
{
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___defaultEncoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___unicodeEncoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___bigEndianUnicode;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf7Encoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf8Encoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___utf32Encoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___asciiEncoding;
	Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* ___latin1Encoding;
	Dictionary_2_t87EDE08B2E48F793A22DE50D6B3CC2E7EBB2DB54* ___encodings;
	RuntimeObject* ___s_InternalSyncObject;
};
struct MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_StaticFields
{
	Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51* ___s_DeserializeFunctionsByName;
};
struct MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_StaticFields
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___k_Ros2Header;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___k_NullByte;
	ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* ___k_PaddingBytes;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE_StaticFields
{
	Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___Null;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031  : public RuntimeArray
{
	ALIGN_FIELD (8) uint8_t m_Items[1];

	inline uint8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint8_t value)
	{
		m_Items[index] = value;
	}
};
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51  : public RuntimeArray
{
	ALIGN_FIELD (8) Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* m_Items[1];

	inline Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913  : public RuntimeArray
{
	ALIGN_FIELD (8) int8_t m_Items[1];

	inline int8_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int8_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int8_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int8_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int8_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int8_t value)
	{
		m_Items[index] = value;
	}
};
struct Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB  : public RuntimeArray
{
	ALIGN_FIELD (8) int16_t m_Items[1];

	inline int16_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int16_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int16_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int16_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int16_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int16_t value)
	{
		m_Items[index] = value;
	}
};
struct UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83  : public RuntimeArray
{
	ALIGN_FIELD (8) uint16_t m_Items[1];

	inline uint16_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint16_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint16_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint16_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint16_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint16_t value)
	{
		m_Items[index] = value;
	}
};
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C  : public RuntimeArray
{
	ALIGN_FIELD (8) int32_t m_Items[1];

	inline int32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int32_t value)
	{
		m_Items[index] = value;
	}
};
struct UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA  : public RuntimeArray
{
	ALIGN_FIELD (8) uint32_t m_Items[1];

	inline uint32_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint32_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint32_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint32_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint32_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint32_t value)
	{
		m_Items[index] = value;
	}
};
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C  : public RuntimeArray
{
	ALIGN_FIELD (8) float m_Items[1];

	inline float GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline float* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, float value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline float GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline float* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, float value)
	{
		m_Items[index] = value;
	}
};
struct DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE  : public RuntimeArray
{
	ALIGN_FIELD (8) double m_Items[1];

	inline double GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline double* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, double value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline double GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline double* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, double value)
	{
		m_Items[index] = value;
	}
};
struct Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D  : public RuntimeArray
{
	ALIGN_FIELD (8) int64_t m_Items[1];

	inline int64_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline int64_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, int64_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline int64_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline int64_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, int64_t value)
	{
		m_Items[index] = value;
	}
};
struct UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299  : public RuntimeArray
{
	ALIGN_FIELD (8) uint64_t m_Items[1];

	inline uint64_t GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline uint64_t* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, uint64_t value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline uint64_t GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline uint64_t* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, uint64_t value)
	{
		m_Items[index] = value;
	}
};
struct ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA  : public RuntimeArray
{
	ALIGN_FIELD (8) ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* m_Items[1];

	inline ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1_set_Item_m3C58DBC69A321AF2826595584FF3E9F43C07EA56_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_mE097DBD72433D1AFC11733F5678602603A756424_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotImplementedException__ctor_m8339D1A685E8D77CAC9D3260C06B38B5C7CA7742 (NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotImplementedException__ctor_mDAB47BC6BD0E342E8F2171E5CABE3E67EA049F1C (NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, int32_t ___0_dataSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BitConverter_ToInt32_m259B4E62995575B80C4086347C867EB3C8D7DAB3 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, int32_t ___1_startIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BitConverter_ToBoolean_mBDA6F9734B907F7BA1135819940F5D6C3E5085FB (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, int32_t ___1_startIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int16_t BitConverter_ToInt16_m13F278223B819C82CC647398B22C125B02FA2E61 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, int32_t ___1_startIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint16_t BitConverter_ToUInt16_m1B08C19B8743A604FBC3807C22A831BD8DA5819D (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, int32_t ___1_startIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float BitConverter_ToSingle_m61C4AA4550F008C0F7681DFF8D6FAE889FA149FD (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, int32_t ___1_startIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double BitConverter_ToDouble_m2F701E24FFE424C6EBDA6CD76CCA029947A535A8 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, int32_t ___1_startIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t BitConverter_ToUInt32_m177FADD1E9B033C11D74E8DD1F957F62EF0BA177 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, int32_t ___1_startIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int64_t BitConverter_ToInt64_mA375995608A3E81761CCA7776461290AC5B262F0 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, int32_t ___1_startIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint64_t BitConverter_ToUInt64_mE7ED21EC4F2485A3AD117BA6DC44E1B6ED16DF23 (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_value, int32_t ___1_startIndex, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t MessageDeserializer_ReadLength_m47A54D7FD84C930D0315E11F398F3AEEDB749099 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m82B22DA76582918DC2FF9771977798BDBF5D49D7 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, String_t** ___0_value, const RuntimeMethod* method) ;
inline bool Dictionary_2_TryGetValue_mDE955F76E376B593C215D78CBD1C4F2A40E60B58 (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* __this, String_t* ___0_key, Func_2_t0B9AE122B87C6F7B2A9654A7B4BD357367C9BD61** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*, String_t*, Func_2_t0B9AE122B87C6F7B2A9654A7B4BD357367C9BD61**, const RuntimeMethod*))Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared)(__this, ___0_key, ___1_value, method);
}
inline void Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85 (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
inline void List_1__ctor_m8070151BA99349188C9F1457EC394480BE0D4ED4 (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
inline void List_1_Clear_m1E9869035CC36C3F683625D97F571B07ECCE756F_inline (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4*, const RuntimeMethod*))List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline)(__this, method);
}
inline int32_t List_1_get_Count_m88FEB2D94E35C258B61F53400F7CA20E99A7DAD3_inline (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4*, const RuntimeMethod*))List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline)(__this, method);
}
inline void List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4*, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t MessageSerializer_get_Length_mBEB2FF00C912C23469C5BE356B3AD57B9B49CA35 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_SerializeMessage_mC4CE2BF559DBB25D23A5894B617BD917B1622549 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverter_GetBytes_mCD74C79673617CEBF85F8A653520C860A9F014F9 (int32_t ___0_value, const RuntimeMethod* method) ;
inline void List_1_set_Item_mE7F925D8AE61B8675A9B04FC14219B71ED5E1F16 (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* __this, int32_t ___0_index, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4*, int32_t, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, const RuntimeMethod*))List_1_set_Item_m3C58DBC69A321AF2826595584FF3E9F43C07EA56_gshared)(__this, ___0_index, ___1_value, method);
}
inline Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC List_1_GetEnumerator_m7C61C1682B2BDC2599320E9B76B12AD7F6E2020D (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC (*) (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4*, const RuntimeMethod*))List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared)(__this, method);
}
inline void Enumerator_Dispose_mCDDC850B62D20A7AAD5DF974538393AB3A43461F (Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC*, const RuntimeMethod*))Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared)(__this, method);
}
inline ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* Enumerator_get_Current_m4B63F6735596A1CA8F6EEA0E6C630CACC3F3900E_inline (Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC* __this, const RuntimeMethod* method)
{
	return ((  ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* (*) (Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC*, const RuntimeMethod*))Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_CopyTo_mFD42E3443AB3B850ED6F19359698E242A08E1BAB (RuntimeArray* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) ;
inline bool Enumerator_MoveNext_m5A8036FD044CA17B6B9F11640135700F7061BFE4 (Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC*, const RuntimeMethod*))Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared)(__this, method);
}
inline void List_1__ctor_m08520634E23EA7BF64AB1B3F668355EEBA35CE2E (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* __this, RuntimeObject* ___0_collection, const RuntimeMethod* method)
{
	((  void (*) (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4*, RuntimeObject*, const RuntimeMethod*))List_1__ctor_mE097DBD72433D1AFC11733F5678602603A756424_gshared)(__this, ___0_collection, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverter_GetBytes_m8129D5C616ECE5D5095473D8A931B65487C770BF (bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, int32_t ___0_dataSize, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverter_GetBytes_m0E92A4A8881B288AF838E6F5C7220210A5AADB15 (int16_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverter_GetBytes_m43CB66A3347C3482B6FB2B3FD327F5327C25E18B (uint16_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverter_GetBytes_m61B5DA2AFDE71BC154C7E0298759972A0A422290 (uint32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverter_GetBytes_m794066816CE7E3AF4A549BC3E41315061A98ADA9 (int64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverter_GetBytes_m46CC8E040C5AB40FFDFBA8562779A3C14E95C7F7 (uint64_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverter_GetBytes_m86ADBB3533A4FFA79B7303FBEBC9EBD1BCA6A549 (float ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* BitConverter_GetBytes_mDFA957490F403B0A6F73768C710649AC18DA227C (double ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358 (RuntimeArray* ___0_src, int32_t ___1_srcOffset, RuntimeArray* ___2_dst, int32_t ___3_dstOffset, int32_t ___4_count, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m312F6ADF2C641C9B93F4E1FC7D416F60034C9B1C (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, String_t* ___0_inputString, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB (RuntimeArray* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
inline void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4 (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared)(__this, ___0_item, method);
}
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Message_SerializeTo_mC64C939239BACD2E5C07AF751A3F623CAD42DA3A (Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF* __this, MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* ___0_state, const RuntimeMethod* method) 
{
	{
		NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8* L_0 = (NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8_il2cpp_TypeInfo_var)));
		NotImplementedException__ctor_m8339D1A685E8D77CAC9D3260C06B38B5C7CA7742(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralAA85FF4E5A7BD42CAFF8E40C42EF0FDF21AF42E2)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Message_SerializeTo_mC64C939239BACD2E5C07AF751A3F623CAD42DA3A_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Message_get_RosMessageName_m14E754F6CF15594CD26BD56211D3853D15A2D050 (Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF* __this, const RuntimeMethod* method) 
{
	{
		NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8* L_0 = (NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotImplementedException_t6366FE4DCF15094C51F4833B91A2AE68D4DA90E8_il2cpp_TypeInfo_var)));
		NotImplementedException__ctor_mDAB47BC6BD0E342E8F2171E5CABE3E67EA049F1C(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Message_get_RosMessageName_m14E754F6CF15594CD26BD56211D3853D15A2D050_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Message__ctor_m1F0994419C135CBD7D85645F56B6D82C73066676 (Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_InitWithBuffer_m9C2A66B791803A036AAF8CF2D7158D8F4826A9BC (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_data, const RuntimeMethod* method) 
{
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_data;
		__this->___data = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___data), (void*)L_0);
		__this->___offset = 0;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, int32_t ___0_dataSize, const RuntimeMethod* method) 
{
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t MessageDeserializer_ReadLength_m47A54D7FD84C930D0315E11F398F3AEEDB749099 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, const RuntimeMethod* method) 
{
	{
		MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF(__this, 4, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = __this->___data;
		int32_t L_1 = __this->___offset;
		int32_t L_2;
		L_2 = BitConverter_ToInt32_m259B4E62995575B80C4086347C867EB3C8D7DAB3(L_0, L_1, NULL);
		int32_t L_3 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_3, 4));
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m338A3F887A313FE384D694F69076D380AF1DBAC3 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, bool* ___0_value, const RuntimeMethod* method) 
{
	{
		bool* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		bool L_3;
		L_3 = BitConverter_ToBoolean_mBDA6F9734B907F7BA1135819940F5D6C3E5085FB(L_1, L_2, NULL);
		*((int8_t*)L_0) = (int8_t)L_3;
		int32_t L_4 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_4, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_mEEAD6E6C07F305AA07365B8C0BAD1E32E9F1473F (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, uint8_t* ___0_value, const RuntimeMethod* method) 
{
	{
		uint8_t* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		uint8_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		*((int8_t*)L_0) = (int8_t)L_4;
		int32_t L_5 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m324D8D40A6127DE02070F2AD6FF7FAE09F98713A (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, int8_t* ___0_value, const RuntimeMethod* method) 
{
	{
		int8_t* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		uint8_t L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		*((int8_t*)L_0) = (int8_t)((int8_t)L_4);
		int32_t L_5 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_5, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m7FB47D4658173E32C0FD36D216285690F4ACB18B (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, int16_t* ___0_value, const RuntimeMethod* method) 
{
	{
		MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF(__this, 2, NULL);
		int16_t* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		int16_t L_3;
		L_3 = BitConverter_ToInt16_m13F278223B819C82CC647398B22C125B02FA2E61(L_1, L_2, NULL);
		*((int16_t*)L_0) = (int16_t)L_3;
		int32_t L_4 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_4, 2));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m7053AFC46AA8A067F1A54C03AA3D52589E6B8A35 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, uint16_t* ___0_value, const RuntimeMethod* method) 
{
	{
		MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF(__this, 2, NULL);
		uint16_t* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		uint16_t L_3;
		L_3 = BitConverter_ToUInt16_m1B08C19B8743A604FBC3807C22A831BD8DA5819D(L_1, L_2, NULL);
		*((int16_t*)L_0) = (int16_t)L_3;
		int32_t L_4 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_4, 2));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_mA49D63D7CE978914FA91D79DFB5703863F24CE94 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, float* ___0_value, const RuntimeMethod* method) 
{
	{
		MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF(__this, 4, NULL);
		float* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		float L_3;
		L_3 = BitConverter_ToSingle_m61C4AA4550F008C0F7681DFF8D6FAE889FA149FD(L_1, L_2, NULL);
		*((float*)L_0) = (float)L_3;
		int32_t L_4 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_4, 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m54046CE4111177676176E0439518460B18D06453 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, double* ___0_value, const RuntimeMethod* method) 
{
	{
		MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF(__this, 8, NULL);
		double* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		double L_3;
		L_3 = BitConverter_ToDouble_m2F701E24FFE424C6EBDA6CD76CCA029947A535A8(L_1, L_2, NULL);
		*((double*)L_0) = (double)L_3;
		int32_t L_4 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_4, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m74D981E7B6EE6B47E3FDCC7928F60CD4418F7061 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, uint32_t* ___0_value, const RuntimeMethod* method) 
{
	{
		MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF(__this, 4, NULL);
		uint32_t* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		uint32_t L_3;
		L_3 = BitConverter_ToUInt32_m177FADD1E9B033C11D74E8DD1F957F62EF0BA177(L_1, L_2, NULL);
		*((int32_t*)L_0) = (int32_t)L_3;
		int32_t L_4 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_4, 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m7BB886F522350724AA8560D7349B800804FCD0B2 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, int32_t* ___0_value, const RuntimeMethod* method) 
{
	{
		MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF(__this, 4, NULL);
		int32_t* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		int32_t L_3;
		L_3 = BitConverter_ToInt32_m259B4E62995575B80C4086347C867EB3C8D7DAB3(L_1, L_2, NULL);
		*((int32_t*)L_0) = (int32_t)L_3;
		int32_t L_4 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_4, 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m5DA63273533BCCF5CEFE961DA7D808B958F6DA24 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, int64_t* ___0_value, const RuntimeMethod* method) 
{
	{
		MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF(__this, 8, NULL);
		int64_t* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		int64_t L_3;
		L_3 = BitConverter_ToInt64_mA375995608A3E81761CCA7776461290AC5B262F0(L_1, L_2, NULL);
		*((int64_t*)L_0) = (int64_t)L_3;
		int32_t L_4 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_4, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m75F61F1809C6A8901D1BF7C42F22C2B1C07068A8 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, uint64_t* ___0_value, const RuntimeMethod* method) 
{
	{
		MessageDeserializer_Align_m840A9B65071FAE2F15E8DB704475590D25BA02BF(__this, 8, NULL);
		uint64_t* L_0 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = __this->___data;
		int32_t L_2 = __this->___offset;
		uint64_t L_3;
		L_3 = BitConverter_ToUInt64_mE7ED21EC4F2485A3AD117BA6DC44E1B6ED16DF23(L_1, L_2, NULL);
		*((int64_t*)L_0) = (int64_t)L_3;
		int32_t L_4 = __this->___offset;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_4, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m82B22DA76582918DC2FF9771977798BDBF5D49D7 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, String_t** ___0_value, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0;
		L_0 = MessageDeserializer_ReadLength_m47A54D7FD84C930D0315E11F398F3AEEDB749099(__this, NULL);
		V_0 = L_0;
		String_t** L_1 = ___0_value;
		Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_2;
		L_2 = Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9(NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = __this->___data;
		int32_t L_4 = __this->___offset;
		int32_t L_5 = V_0;
		NullCheck(L_2);
		String_t* L_6;
		L_6 = VirtualFuncInvoker3< String_t*, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, int32_t, int32_t >::Invoke(34, L_2, L_3, L_4, L_5);
		*((RuntimeObject**)L_1) = (RuntimeObject*)L_6;
		Il2CppCodeGenWriteBarrier((void**)(RuntimeObject**)L_1, (void*)(RuntimeObject*)L_6);
		int32_t L_7 = __this->___offset;
		int32_t L_8 = V_0;
		__this->___offset = ((int32_t)il2cpp_codegen_add(L_7, L_8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer_Read_m17C4D39EABA12E946B208A6A57C1B17B2A7D1357 (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248** ___0_values, int32_t ___1_length, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248** L_0 = ___0_values;
		int32_t L_1 = ___1_length;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = (StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248*)SZArrayNew(StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248_il2cpp_TypeInfo_var, (uint32_t)L_1);
		*((RuntimeObject**)L_0) = (RuntimeObject*)L_2;
		Il2CppCodeGenWriteBarrier((void**)(RuntimeObject**)L_0, (void*)(RuntimeObject*)L_2);
		V_0 = 0;
		goto IL_001e;
	}

IL_000c:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248** L_3 = ___0_values;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_4 = *((StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248**)L_3);
		int32_t L_5 = V_0;
		NullCheck(L_4);
		MessageDeserializer_Read_m82B22DA76582918DC2FF9771977798BDBF5D49D7(__this, ((L_4)->GetAddressAt(static_cast<il2cpp_array_size_t>(L_5))), NULL);
		int32_t L_6 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_001e:
	{
		int32_t L_7 = V_0;
		int32_t L_8 = ___1_length;
		if ((((int32_t)L_7) < ((int32_t)L_8)))
		{
			goto IL_000c;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageDeserializer__ctor_m28F8BD45C8B3C8EC0EEFCDA822ECBD796897989F (MessageDeserializer_tB7A06A4B097DD01A2E35E9AFEB085164A41603FF* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Func_2_t0B9AE122B87C6F7B2A9654A7B4BD357367C9BD61* MessageRegistry_GetDeserializeFunction_m96349FA3733FE2EF439856808131AB7C4A9B5081 (String_t* ___0_rosMessageName, int32_t ___1_subtopic, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_mDE955F76E376B593C215D78CBD1C4F2A40E60B58_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Func_2_t0B9AE122B87C6F7B2A9654A7B4BD357367C9BD61* V_0 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_il2cpp_TypeInfo_var);
		Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51* L_0 = ((MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_StaticFields*)il2cpp_codegen_static_fields_for(MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_il2cpp_TypeInfo_var))->___s_DeserializeFunctionsByName;
		int32_t L_1 = ___1_subtopic;
		NullCheck(L_0);
		int32_t L_2 = L_1;
		Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* L_3 = (L_0)->GetAt(static_cast<il2cpp_array_size_t>(L_2));
		String_t* L_4 = ___0_rosMessageName;
		NullCheck(L_3);
		bool L_5;
		L_5 = Dictionary_2_TryGetValue_mDE955F76E376B593C215D78CBD1C4F2A40E60B58(L_3, L_4, (&V_0), Dictionary_2_TryGetValue_mDE955F76E376B593C215D78CBD1C4F2A40E60B58_RuntimeMethod_var);
		Func_2_t0B9AE122B87C6F7B2A9654A7B4BD357367C9BD61* L_6 = V_0;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageRegistry__cctor_m1526CD31492CA0B808EDE87FEB8D404494B6CA4A (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51* L_0 = (Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51*)(Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51*)SZArrayNew(Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51_il2cpp_TypeInfo_var, (uint32_t)5);
		Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51* L_1 = L_0;
		Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* L_2 = (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*)il2cpp_codegen_object_new(Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2_il2cpp_TypeInfo_var);
		Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85(L_2, Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85_RuntimeMethod_var);
		NullCheck(L_1);
		ArrayElementTypeCheck (L_1, L_2);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(0), (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*)L_2);
		Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51* L_3 = L_1;
		Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* L_4 = (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*)il2cpp_codegen_object_new(Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2_il2cpp_TypeInfo_var);
		Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85(L_4, Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85_RuntimeMethod_var);
		NullCheck(L_3);
		ArrayElementTypeCheck (L_3, L_4);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(1), (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*)L_4);
		Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51* L_5 = L_3;
		Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* L_6 = (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*)il2cpp_codegen_object_new(Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2_il2cpp_TypeInfo_var);
		Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85(L_6, Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85_RuntimeMethod_var);
		NullCheck(L_5);
		ArrayElementTypeCheck (L_5, L_6);
		(L_5)->SetAt(static_cast<il2cpp_array_size_t>(2), (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*)L_6);
		Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51* L_7 = L_5;
		Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* L_8 = (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*)il2cpp_codegen_object_new(Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2_il2cpp_TypeInfo_var);
		Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85(L_8, Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85_RuntimeMethod_var);
		NullCheck(L_7);
		ArrayElementTypeCheck (L_7, L_8);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(3), (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*)L_8);
		Dictionary_2U5BU5D_tF043A54D93A67689869C28C9BADEFD0CAADD3B51* L_9 = L_7;
		Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2* L_10 = (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*)il2cpp_codegen_object_new(Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2_il2cpp_TypeInfo_var);
		Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85(L_10, Dictionary_2__ctor_m50CFF23A7254CCCD3A1320D359DA0AD906247E85_RuntimeMethod_var);
		NullCheck(L_9);
		ArrayElementTypeCheck (L_9, L_10);
		(L_9)->SetAt(static_cast<il2cpp_array_size_t>(4), (Dictionary_2_tABE95D7A3327DAB6E0FEEE812FDFC0CA5360D9B2*)L_10);
		((MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_StaticFields*)il2cpp_codegen_static_fields_for(MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_il2cpp_TypeInfo_var))->___s_DeserializeFunctionsByName = L_9;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_StaticFields*)il2cpp_codegen_static_fields_for(MessageRegistry_tC801955B80E2C9916BA4451873A8F5774BEA86EC_il2cpp_TypeInfo_var))->___s_DeserializeFunctionsByName), (void*)L_9);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t MessageSerializer_get_Length_mBEB2FF00C912C23469C5BE356B3AD57B9B49CA35 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___m_AlignmentOffset;
		int32_t L_1 = __this->___m_LengthCorrection;
		return ((int32_t)il2cpp_codegen_add(L_0, L_1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer__ctor_m728038C7A1727A6E96451976CB0CDD7EF37F6908 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m8070151BA99349188C9F1457EC394480BE0D4ED4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4*)il2cpp_codegen_object_new(List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4_il2cpp_TypeInfo_var);
		List_1__ctor_m8070151BA99349188C9F1457EC394480BE0D4ED4(L_0, List_1__ctor_m8070151BA99349188C9F1457EC394480BE0D4ED4_RuntimeMethod_var);
		__this->___m_ListOfSerializations = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___m_ListOfSerializations), (void*)L_0);
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Clear_m8DF3A14E104AA5088A23A8036E8228FB065537A7 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Clear_m1E9869035CC36C3F683625D97F571B07ECCE756F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		__this->___m_AlignmentOffset = 0;
		__this->___m_LengthCorrection = 0;
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		NullCheck(L_0);
		List_1_Clear_m1E9869035CC36C3F683625D97F571B07ECCE756F_inline(L_0, List_1_Clear_m1E9869035CC36C3F683625D97F571B07ECCE756F_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_SerializeMessageWithLength_mA0684C7A158796DD8F5BF43D6246A1E90F9F751F (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF* ___0_message, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m88FEB2D94E35C258B61F53400F7CA20E99A7DAD3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_set_Item_mE7F925D8AE61B8675A9B04FC14219B71ED5E1F16_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = List_1_get_Count_m88FEB2D94E35C258B61F53400F7CA20E99A7DAD3_inline(L_0, List_1_get_Count_m88FEB2D94E35C258B61F53400F7CA20E99A7DAD3_RuntimeMethod_var);
		V_0 = L_1;
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_2 = __this->___m_ListOfSerializations;
		NullCheck(L_2);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_2, (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)NULL, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_LengthCorrection;
		__this->___m_LengthCorrection = ((int32_t)il2cpp_codegen_add(L_3, 4));
		int32_t L_4;
		L_4 = MessageSerializer_get_Length_mBEB2FF00C912C23469C5BE356B3AD57B9B49CA35(__this, NULL);
		V_1 = L_4;
		Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF* L_5 = ___0_message;
		MessageSerializer_SerializeMessage_mC4CE2BF559DBB25D23A5894B617BD917B1622549(__this, L_5, NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		int32_t L_7 = V_0;
		int32_t L_8;
		L_8 = MessageSerializer_get_Length_mBEB2FF00C912C23469C5BE356B3AD57B9B49CA35(__this, NULL);
		int32_t L_9 = V_1;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_10;
		L_10 = BitConverter_GetBytes_mCD74C79673617CEBF85F8A653520C860A9F014F9(((int32_t)il2cpp_codegen_subtract(L_8, L_9)), NULL);
		NullCheck(L_6);
		List_1_set_Item_mE7F925D8AE61B8675A9B04FC14219B71ED5E1F16(L_6, L_7, L_10, List_1_set_Item_mE7F925D8AE61B8675A9B04FC14219B71ED5E1F16_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_SerializeMessage_mC4CE2BF559DBB25D23A5894B617BD917B1622549 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF* ___0_message, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___m_LengthCorrection;
		int32_t L_1 = __this->___m_AlignmentOffset;
		__this->___m_LengthCorrection = ((int32_t)il2cpp_codegen_add(L_0, L_1));
		__this->___m_AlignmentOffset = 0;
		Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF* L_2 = ___0_message;
		NullCheck(L_2);
		VirtualActionInvoker1< MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* >::Invoke(4, L_2, __this);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* MessageSerializer_GetBytes_mFA5E11897173FB1B8FA4A5AB5573F0A74C862372 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_mCDDC850B62D20A7AAD5DF974538393AB3A43461F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m5A8036FD044CA17B6B9F11640135700F7061BFE4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_m4B63F6735596A1CA8F6EEA0E6C630CACC3F3900E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m7C61C1682B2BDC2599320E9B76B12AD7F6E2020D_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	int32_t V_1 = 0;
	Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC V_2;
	memset((&V_2), 0, sizeof(V_2));
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_3 = NULL;
	{
		int32_t L_0;
		L_0 = MessageSerializer_get_Length_mBEB2FF00C912C23469C5BE356B3AD57B9B49CA35(__this, NULL);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)L_0);
		V_0 = L_1;
		V_1 = 0;
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_2 = __this->___m_ListOfSerializations;
		NullCheck(L_2);
		Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC L_3;
		L_3 = List_1_GetEnumerator_m7C61C1682B2BDC2599320E9B76B12AD7F6E2020D(L_2, List_1_GetEnumerator_m7C61C1682B2BDC2599320E9B76B12AD7F6E2020D_RuntimeMethod_var);
		V_2 = L_3;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0040:
			{
				Enumerator_Dispose_mCDDC850B62D20A7AAD5DF974538393AB3A43461F((&V_2), Enumerator_Dispose_mCDDC850B62D20A7AAD5DF974538393AB3A43461F_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0035_1;
			}

IL_001c_1:
			{
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4;
				L_4 = Enumerator_get_Current_m4B63F6735596A1CA8F6EEA0E6C630CACC3F3900E_inline((&V_2), Enumerator_get_Current_m4B63F6735596A1CA8F6EEA0E6C630CACC3F3900E_RuntimeMethod_var);
				V_3 = L_4;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_3;
				if (!L_5)
				{
					goto IL_0035_1;
				}
			}
			{
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_6 = V_3;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
				int32_t L_8 = V_1;
				NullCheck((RuntimeArray*)L_6);
				Array_CopyTo_mFD42E3443AB3B850ED6F19359698E242A08E1BAB((RuntimeArray*)L_6, (RuntimeArray*)L_7, L_8, NULL);
				int32_t L_9 = V_1;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_10 = V_3;
				NullCheck(L_10);
				V_1 = ((int32_t)il2cpp_codegen_add(L_9, ((int32_t)(((RuntimeArray*)L_10)->max_length))));
			}

IL_0035_1:
			{
				bool L_11;
				L_11 = Enumerator_MoveNext_m5A8036FD044CA17B6B9F11640135700F7061BFE4((&V_2), Enumerator_MoveNext_m5A8036FD044CA17B6B9F11640135700F7061BFE4_RuntimeMethod_var);
				if (L_11)
				{
					goto IL_001c_1;
				}
			}
			{
				goto IL_004e;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_004e:
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_12 = V_0;
		return L_12;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* MessageSerializer_GetBytesSequence_m61729B751207E3EC9868129F0D9F0D6B2DF80E9B (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m08520634E23EA7BF64AB1B3F668355EEBA35CE2E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_1 = (List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4*)il2cpp_codegen_object_new(List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4_il2cpp_TypeInfo_var);
		List_1__ctor_m08520634E23EA7BF64AB1B3F668355EEBA35CE2E(L_1, L_0, List_1__ctor_m08520634E23EA7BF64AB1B3F668355EEBA35CE2E_RuntimeMethod_var);
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_SendTo_mAEA1CD180F562D6809E3AB6A28CB9FDBBA3D43CA (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* ___0_stream, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_mCDDC850B62D20A7AAD5DF974538393AB3A43461F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m5A8036FD044CA17B6B9F11640135700F7061BFE4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_m4B63F6735596A1CA8F6EEA0E6C630CACC3F3900E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m7C61C1682B2BDC2599320E9B76B12AD7F6E2020D_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC V_0;
	memset((&V_0), 0, sizeof(V_0));
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_1 = NULL;
	{
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		NullCheck(L_0);
		Enumerator_t58043958B4360A01DE08893E29EBFD6A73120CEC L_1;
		L_1 = List_1_GetEnumerator_m7C61C1682B2BDC2599320E9B76B12AD7F6E2020D(L_0, List_1_GetEnumerator_m7C61C1682B2BDC2599320E9B76B12AD7F6E2020D_RuntimeMethod_var);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_002c:
			{
				Enumerator_Dispose_mCDDC850B62D20A7AAD5DF974538393AB3A43461F((&V_0), Enumerator_Dispose_mCDDC850B62D20A7AAD5DF974538393AB3A43461F_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0021_1;
			}

IL_000e_1:
			{
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
				L_2 = Enumerator_get_Current_m4B63F6735596A1CA8F6EEA0E6C630CACC3F3900E_inline((&V_0), Enumerator_get_Current_m4B63F6735596A1CA8F6EEA0E6C630CACC3F3900E_RuntimeMethod_var);
				V_1 = L_2;
				Stream_tF844051B786E8F7F4244DBD218D74E8617B9A2DE* L_3 = ___0_stream;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_1;
				ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_1;
				NullCheck(L_5);
				NullCheck(L_3);
				VirtualActionInvoker3< ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, int32_t, int32_t >::Invoke(32, L_3, L_4, 0, ((int32_t)(((RuntimeArray*)L_5)->max_length)));
			}

IL_0021_1:
			{
				bool L_6;
				L_6 = Enumerator_MoveNext_m5A8036FD044CA17B6B9F11640135700F7061BFE4((&V_0), Enumerator_MoveNext_m5A8036FD044CA17B6B9F11640135700F7061BFE4_RuntimeMethod_var);
				if (L_6)
				{
					goto IL_000e_1;
				}
			}
			{
				goto IL_003a;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, int32_t ___0_dataSize, const RuntimeMethod* method) 
{
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m613055761C27F6318B64533D2DA22356BEB98317 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF* ___0_message, const RuntimeMethod* method) 
{
	{
		Message_tBD8A361BD6D49D4FF433A098AE3E5EE758F160FF* L_0 = ___0_message;
		NullCheck(L_0);
		VirtualActionInvoker1< MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* >::Invoke(4, L_0, __this);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mCE38AE0340B808C27B28795946DE64DBDB319A3A (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		bool L_1 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = BitConverter_GetBytes_m8129D5C616ECE5D5095473D8A931B65487C770BF(L_1, NULL);
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_3, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mCFB1B5B2844DC7A2589EDC9D11FF9F306981617A (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, uint8_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = L_1;
		uint8_t L_3 = ___0_value;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(0), (uint8_t)L_3);
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_4 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_4, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m46DC483AE61EFD959F04DE5580DD84A96684ABD3 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, int8_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = L_1;
		int8_t L_3 = ___0_value;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(0), (uint8_t)((int32_t)(uint8_t)L_3));
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_4 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_4, 1));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m589A0672E7E02A27E01F164E9136D3CE32C88786 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, int16_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 2, NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		int16_t L_1 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = BitConverter_GetBytes_m0E92A4A8881B288AF838E6F5C7220210A5AADB15(L_1, NULL);
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_3, 2));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mE1E9AEEF5E2236A9BA31ABEE46B4EE6854F44E77 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, uint16_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 2, NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		uint16_t L_1 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = BitConverter_GetBytes_m43CB66A3347C3482B6FB2B3FD327F5327C25E18B(L_1, NULL);
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_3, 2));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mCE95E66B6BFA2E0382A1C65748319D7110B52C6A (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 4, NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		int32_t L_1 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = BitConverter_GetBytes_mCD74C79673617CEBF85F8A653520C860A9F014F9(L_1, NULL);
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_3, 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mA8A5F77841480A762255B304DA5AF45F3CF94D46 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, uint32_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 4, NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		uint32_t L_1 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = BitConverter_GetBytes_m61B5DA2AFDE71BC154C7E0298759972A0A422290(L_1, NULL);
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_3, 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mEF8C88E3A504F9A6AACEE6EFFF5BB696A534AFB6 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, int64_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 8, NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		int64_t L_1 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = BitConverter_GetBytes_m794066816CE7E3AF4A549BC3E41315061A98ADA9(L_1, NULL);
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_3, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mB2429CB37627E241E3F3419B9A129A178EAF113C (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, uint64_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 8, NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		uint64_t L_1 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = BitConverter_GetBytes_m46CC8E040C5AB40FFDFBA8562779A3C14E95C7F7(L_1, NULL);
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_3, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m021DAEA22795AA327AB9D673B6204E863D363874 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, float ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 4, NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		float L_1 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = BitConverter_GetBytes_m86ADBB3533A4FFA79B7303FBEBC9EBD1BCA6A549(L_1, NULL);
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_3, 4));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m638B6A51624E443C227F596971EEECA0BBC045CB (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, double ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 8, NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_0 = __this->___m_ListOfSerializations;
		double L_1 = ___0_value;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = BitConverter_GetBytes_mDFA957490F403B0A6F73768C710649AC18DA227C(L_1, NULL);
		NullCheck(L_0);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_0, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_AlignmentOffset;
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_3, 8));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m0630C15D372A317E20C391155D4D0D955A728FFA (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___0_values, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = ___0_values;
		NullCheck(L_0);
		if ((((RuntimeArray*)L_0)->max_length))
		{
			goto IL_0005;
		}
	}
	{
		return;
	}

IL_0005:
	{
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_1 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = ___0_values;
		NullCheck(L_1);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_1, L_2, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_3 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = ___0_values;
		NullCheck(L_4);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_3, ((int32_t)(((RuntimeArray*)L_4)->max_length))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mB4723DE42458A2E2E829A92888EEDC5B144B2718 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* ___0_values, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* L_0 = ___0_values;
		NullCheck(L_0);
		if ((((RuntimeArray*)L_0)->max_length))
		{
			goto IL_0005;
		}
	}
	{
		return;
	}

IL_0005:
	{
		SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* L_1 = ___0_values;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)(((RuntimeArray*)L_1)->max_length)));
		V_0 = L_2;
		SByteU5BU5D_t88116DA68378C3333DB73E7D36C1A06AFAA91913* L_3 = ___0_values;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)(((RuntimeArray*)L_9)->max_length))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m5E826A6241B8BFEB64BB7A62BDF81006B08B0464 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* ___0_values, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_0 = ___0_values;
		NullCheck(L_0);
		if ((((RuntimeArray*)L_0)->max_length))
		{
			goto IL_0005;
		}
	}
	{
		return;
	}

IL_0005:
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 2, NULL);
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_1 = ___0_values;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_1)->max_length)), 2)));
		V_0 = L_2;
		Int16U5BU5D_t8175CE8DD9C9F9FB0CF4F58E45BC570575B43CFB* L_3 = ___0_values;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)(((RuntimeArray*)L_9)->max_length))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m84BDDE83D4FFAD06D53C96804B4BB35B1985DC1F (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83* ___0_values, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83* L_0 = ___0_values;
		NullCheck(L_0);
		if ((((RuntimeArray*)L_0)->max_length))
		{
			goto IL_0005;
		}
	}
	{
		return;
	}

IL_0005:
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 2, NULL);
		UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83* L_1 = ___0_values;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_1)->max_length)), 2)));
		V_0 = L_2;
		UInt16U5BU5D_tEB7C42D811D999D2AA815BADC3FCCDD9C67B3F83* L_3 = ___0_values;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)(((RuntimeArray*)L_9)->max_length))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m4FD7966965554BCF7A8DF54AAFA8D55139261A85 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ___0_values, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_0 = ___0_values;
		NullCheck(L_0);
		if ((((RuntimeArray*)L_0)->max_length))
		{
			goto IL_0005;
		}
	}
	{
		return;
	}

IL_0005:
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 4, NULL);
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_1 = ___0_values;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_1)->max_length)), 4)));
		V_0 = L_2;
		Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* L_3 = ___0_values;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)(((RuntimeArray*)L_9)->max_length))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mF1C6DB0D1236C681DFDA14F7E5C5119E27ED4B1F (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* ___0_values, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* L_0 = ___0_values;
		NullCheck(L_0);
		if ((((RuntimeArray*)L_0)->max_length))
		{
			goto IL_0005;
		}
	}
	{
		return;
	}

IL_0005:
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 4, NULL);
		UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* L_1 = ___0_values;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_1)->max_length)), 4)));
		V_0 = L_2;
		UInt32U5BU5D_t02FBD658AD156A17574ECE6106CF1FBFCC9807FA* L_3 = ___0_values;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)(((RuntimeArray*)L_9)->max_length))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mF281FED15CDA48967F52949B5885CA43EB9455EE (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___0_values, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_0 = ___0_values;
		NullCheck(L_0);
		if ((((RuntimeArray*)L_0)->max_length))
		{
			goto IL_0005;
		}
	}
	{
		return;
	}

IL_0005:
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 4, NULL);
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_1 = ___0_values;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_1)->max_length)), 4)));
		V_0 = L_2;
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_3 = ___0_values;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)(((RuntimeArray*)L_9)->max_length))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_mE62A6A28F6FB1C84304CCB2B1E18C4D211F04C74 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* ___0_values, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* L_0 = ___0_values;
		NullCheck(L_0);
		if ((((RuntimeArray*)L_0)->max_length))
		{
			goto IL_0005;
		}
	}
	{
		return;
	}

IL_0005:
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 8, NULL);
		DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* L_1 = ___0_values;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_1)->max_length)), 8)));
		V_0 = L_2;
		DoubleU5BU5D_tCC308475BD3B8229DB2582938669EF2F9ECC1FEE* L_3 = ___0_values;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)(((RuntimeArray*)L_9)->max_length))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m45812E854EE150F3A33288E94935D1D153468D77 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D* ___0_values, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D* L_0 = ___0_values;
		NullCheck(L_0);
		if ((((RuntimeArray*)L_0)->max_length))
		{
			goto IL_0005;
		}
	}
	{
		return;
	}

IL_0005:
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 8, NULL);
		Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D* L_1 = ___0_values;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_1)->max_length)), 8)));
		V_0 = L_2;
		Int64U5BU5D_tAEDFCBDB5414E2A140A6F34C0538BF97FCF67A1D* L_3 = ___0_values;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)(((RuntimeArray*)L_9)->max_length))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m9E00AAB7E33DF9276D9B6B4E46E4B63318B72831 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299* ___0_values, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299* L_0 = ___0_values;
		NullCheck(L_0);
		if ((((RuntimeArray*)L_0)->max_length))
		{
			goto IL_0005;
		}
	}
	{
		return;
	}

IL_0005:
	{
		MessageSerializer_Align_mA0937D1D85F64B0E995AC382913D4D1FA0DC0B14(__this, 8, NULL);
		UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299* L_1 = ___0_values;
		NullCheck(L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)il2cpp_codegen_multiply(((int32_t)(((RuntimeArray*)L_1)->max_length)), 8)));
		V_0 = L_2;
		UInt64U5BU5D_tAB1A62450AC0899188486EDB9FC066B8BEED9299* L_3 = ___0_values;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = V_0;
		NullCheck(L_5);
		Buffer_BlockCopy_m2F7BC0C5BA97C500E3F87D5008718F797E02B358((RuntimeArray*)L_3, 0, (RuntimeArray*)L_4, 0, ((int32_t)(((RuntimeArray*)L_5)->max_length)), NULL);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)(((RuntimeArray*)L_9)->max_length))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m312F6ADF2C641C9B93F4E1FC7D416F60034C9B1C (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, String_t* ___0_inputString, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_0;
		L_0 = Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9(NULL);
		String_t* L_1 = ___0_inputString;
		NullCheck(L_0);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = VirtualFuncInvoker1< ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, String_t* >::Invoke(17, L_0, L_1);
		V_0 = L_2;
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_3 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		NullCheck(L_4);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5;
		L_5 = BitConverter_GetBytes_mCD74C79673617CEBF85F8A653520C860A9F014F9(((int32_t)(((RuntimeArray*)L_4)->max_length)), NULL);
		NullCheck(L_3);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_3, L_5, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)il2cpp_codegen_add(4, ((int32_t)(((RuntimeArray*)L_9)->max_length))))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_WriteUnaligned_m906625DE58CAAD2A2D8B958D629F7014BE83C5B2 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, String_t* ___0_inputString, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* V_0 = NULL;
	{
		Encoding_t65CDEF28CF20A7B8C92E85A4E808920C2465F095* L_0;
		L_0 = Encoding_get_UTF8_m9FA98A53CE96FD6D02982625C5246DD36C1235C9(NULL);
		String_t* L_1 = ___0_inputString;
		NullCheck(L_0);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2;
		L_2 = VirtualFuncInvoker1< ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*, String_t* >::Invoke(17, L_0, L_1);
		V_0 = L_2;
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_3 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = V_0;
		NullCheck(L_4);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5;
		L_5 = BitConverter_GetBytes_mCD74C79673617CEBF85F8A653520C860A9F014F9(((int32_t)(((RuntimeArray*)L_4)->max_length)), NULL);
		NullCheck(L_3);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_3, L_5, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		List_1_tBFF9DD9FFA06F20E74F9D7AD36610BD754D353A4* L_6 = __this->___m_ListOfSerializations;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = V_0;
		NullCheck(L_6);
		List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_inline(L_6, L_7, List_1_Add_mAF067D8BCD6732A0ADBE1BA6EE909B3512880D42_RuntimeMethod_var);
		int32_t L_8 = __this->___m_AlignmentOffset;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = V_0;
		NullCheck(L_9);
		__this->___m_AlignmentOffset = ((int32_t)il2cpp_codegen_add(L_8, ((int32_t)il2cpp_codegen_add(4, ((int32_t)(((RuntimeArray*)L_9)->max_length))))));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer_Write_m0FA0D2770B7015DE5DB5BC45F5D034866D92DC94 (MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7* __this, StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___0_values, const RuntimeMethod* method) 
{
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* V_0 = NULL;
	int32_t V_1 = 0;
	String_t* V_2 = NULL;
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_0 = ___0_values;
		V_0 = L_0;
		V_1 = 0;
		goto IL_0015;
	}

IL_0006:
	{
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_1 = V_0;
		int32_t L_2 = V_1;
		NullCheck(L_1);
		int32_t L_3 = L_2;
		String_t* L_4 = (L_1)->GetAt(static_cast<il2cpp_array_size_t>(L_3));
		V_2 = L_4;
		String_t* L_5 = V_2;
		MessageSerializer_Write_m312F6ADF2C641C9B93F4E1FC7D416F60034C9B1C(__this, L_5, NULL);
		int32_t L_6 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_6, 1));
	}

IL_0015:
	{
		int32_t L_7 = V_1;
		StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_8 = V_0;
		NullCheck(L_8);
		if ((((int32_t)L_7) < ((int32_t)((int32_t)(((RuntimeArray*)L_8)->max_length)))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MessageSerializer__cctor_m6004C2F468D6496DA28BF022B15E3BF17E2D96C5 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)4);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = L_0;
		NullCheck(L_1);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(1), (uint8_t)1);
		((MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_StaticFields*)il2cpp_codegen_static_fields_for(MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_il2cpp_TypeInfo_var))->___k_Ros2Header = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_StaticFields*)il2cpp_codegen_static_fields_for(MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_il2cpp_TypeInfo_var))->___k_Ros2Header), (void*)L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_2 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)1);
		((MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_StaticFields*)il2cpp_codegen_static_fields_for(MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_il2cpp_TypeInfo_var))->___k_NullByte = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_StaticFields*)il2cpp_codegen_static_fields_for(MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_il2cpp_TypeInfo_var))->___k_NullByte), (void*)L_2);
		ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* L_3 = (ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA*)(ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA*)SZArrayNew(ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA_il2cpp_TypeInfo_var, (uint32_t)((int32_t)9));
		ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* L_4 = L_3;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_5 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)1);
		NullCheck(L_4);
		(L_4)->SetAt(static_cast<il2cpp_array_size_t>(1), (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)L_5);
		ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* L_6 = L_4;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_7 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)2);
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(2), (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)L_7);
		ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* L_8 = L_6;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_9 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)3);
		NullCheck(L_8);
		(L_8)->SetAt(static_cast<il2cpp_array_size_t>(3), (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)L_9);
		ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* L_10 = L_8;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_11 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)4);
		NullCheck(L_10);
		(L_10)->SetAt(static_cast<il2cpp_array_size_t>(4), (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)L_11);
		ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* L_12 = L_10;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_13 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)5);
		NullCheck(L_12);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(5), (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)L_13);
		ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* L_14 = L_12;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_15 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)6);
		NullCheck(L_14);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(6), (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)L_15);
		ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* L_16 = L_14;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_17 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)7);
		NullCheck(L_16);
		(L_16)->SetAt(static_cast<il2cpp_array_size_t>(7), (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)L_17);
		ByteU5BU5DU5BU5D_t19A0C6D66F22DF673E9CDB37DEF566FE0EC947FA* L_18 = L_16;
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_19 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)8);
		NullCheck(L_18);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(8), (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)L_19);
		((MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_StaticFields*)il2cpp_codegen_static_fields_for(MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_il2cpp_TypeInfo_var))->___k_PaddingBytes = L_18;
		Il2CppCodeGenWriteBarrier((void**)(&((MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_StaticFields*)il2cpp_codegen_static_fields_for(MessageSerializer_tF85A77B0C9BAB7548B9EC879E5E651CEACA95AF7_il2cpp_TypeInfo_var))->___k_PaddingBytes), (void*)L_18);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
	}
	{
		int32_t L_1 = __this->____size;
		V_0 = L_1;
		__this->____size = 0;
		int32_t L_2 = V_0;
		if ((((int32_t)L_2) <= ((int32_t)0)))
		{
			goto IL_003c;
		}
	}
	{
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_3 = __this->____items;
		int32_t L_4 = V_0;
		Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB((RuntimeArray*)L_3, 0, L_4, NULL);
		return;
	}

IL_003c:
	{
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) 
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_0 = NULL;
	int32_t V_1 = 0;
	{
		int32_t L_0 = __this->____version;
		__this->____version = ((int32_t)il2cpp_codegen_add(L_0, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_1 = __this->____items;
		V_0 = L_1;
		int32_t L_2 = __this->____size;
		V_1 = L_2;
		int32_t L_3 = V_1;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_4 = V_0;
		NullCheck(L_4);
		if ((!(((uint32_t)L_3) < ((uint32_t)((int32_t)(((RuntimeArray*)L_4)->max_length))))))
		{
			goto IL_0034;
		}
	}
	{
		int32_t L_5 = V_1;
		__this->____size = ((int32_t)il2cpp_codegen_add(L_5, 1));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_6 = V_0;
		int32_t L_7 = V_1;
		RuntimeObject* L_8 = ___0_item;
		NullCheck(L_6);
		(L_6)->SetAt(static_cast<il2cpp_array_size_t>(L_7), (RuntimeObject*)L_8);
		return;
	}

IL_0034:
	{
		RuntimeObject* L_9 = ___0_item;
		List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4(__this, L_9, il2cpp_rgctx_method(method->klass->rgctx_data, 14));
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->____current;
		return L_0;
	}
}
