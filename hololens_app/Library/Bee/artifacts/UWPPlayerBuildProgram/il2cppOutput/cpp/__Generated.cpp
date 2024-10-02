#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct InterfaceActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename T1, typename T2>
struct InterfaceActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R, typename T1>
struct InterfaceFuncInvoker1
{
	typedef R (*Func)(void*, T1, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R, typename T1, typename T2>
struct InterfaceFuncInvoker2
{
	typedef R (*Func)(void*, T1, T2, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};

struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263;
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129;
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F;
struct Exception_t;
struct IBindableIterableToIEnumerableAdapter_t8388E8C2838435C66EE4B1B25C5D7BA613F5E062;
struct IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F;
struct IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A;
struct IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C;
struct IClosableToIDisposableAdapter_tD6218CE13709C28F778EE324FAF6DC9799DFEE7D;
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
struct IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA;
struct IInspectableToICollectionAdapter_t79A837B414D58B2BDA9B2AC57925247E5A3F982E;
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB;
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A;
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
struct String_t;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct __Il2CppComDelegate_tD0DD2BBA6AC8F151D32B6DFD02F6BDA339F8DC4D;
struct Il2CppComObject;

IL2CPP_EXTERN_C RuntimeClass* ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IClosable_t408735E2F18F562F8A87A4C359E73D7C30A1D301_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral18E7747DF396126C8F06504578145283EC80CCE2;
IL2CPP_EXTERN_C String_t* _stringLiteral2390D6884F59E2E4EA04837AD7D6268548597633;
IL2CPP_EXTERN_C String_t* _stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1;
IL2CPP_EXTERN_C String_t* _stringLiteral601864F27855188434B3BC9664592B159BD53FA6;
IL2CPP_EXTERN_C String_t* _stringLiteral834F4B6837B71847C4048C946DF8754B323D6BF9;
IL2CPP_EXTERN_C String_t* _stringLiteral893C6A70E6986916540A62EB89DF7EE2457D3DC8;
IL2CPP_EXTERN_C String_t* _stringLiteral94046C5588508CC292E2C8D101FD4A30B1AA35FE;
IL2CPP_EXTERN_C String_t* _stringLiteral94FD93033ADDABB82341E25C5060807B4D72DE0B;
IL2CPP_EXTERN_C String_t* _stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED;
IL2CPP_EXTERN_C String_t* _stringLiteralC67981104B030F2C9B107A0F7873A4F201E95009;
IL2CPP_EXTERN_C String_t* _stringLiteralD1EB4ADB9F8DAF79365F268B73404FB4E6318BCC;
IL2CPP_EXTERN_C String_t* _stringLiteralDA70662AC1619107177B004460D78346FFAE295D;
IL2CPP_EXTERN_C String_t* _stringLiteralE6200FC24048842D4802BFB4F92BEE9C12FE7A9E;
IL2CPP_EXTERN_C String_t* _stringLiteralF8D08FCF1537043BF0289FA98C51BF5A3AC7C618;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableIteratorToIEnumeratorAdapter_System_Collections_IEnumerator_MoveNext_mDAD00541F5B2D7652EDD9B31C6AF884783219F55_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableIteratorToIEnumeratorAdapter_System_Collections_IEnumerator_Reset_mAA1156ED1002B068A4D650A4A8299EDC9BD9AE8E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableIteratorToIEnumeratorAdapter_System_Collections_IEnumerator_get_Current_mCD38EF40228F1C884E89C162679AC9C96FAD3482_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableVectorToIListAdapter_System_Collections_ICollection_CopyTo_m2CDA4A8C4FCA77BE2594E6E6F749A1A74FAA0312_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableVectorToIListAdapter_System_Collections_ICollection_get_Count_m845690015DDDE5D20B2E7DA2377A36F0DFD89BC5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableVectorToIListAdapter_System_Collections_ICollection_get_IsSynchronized_mEC643873CFA92251AF8E8C346B358D4E9BACFAAE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableVectorToIListAdapter_System_Collections_ICollection_get_SyncRoot_m7600DD62C4B3CEBDBE7258CAF93503BB2D8ABDD8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableVectorToIListAdapter_System_Collections_IEnumerable_GetEnumerator_mDAF2E67C36C34579822F83A90B36CBB09D7247CC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableVectorToIListAdapter_System_Collections_IList_IndexOf_m6F630822791D1DC1303F642621EFB684CB1F8BC1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableVectorToIListAdapter_System_Collections_IList_Insert_m88FA248F41D748BB6DF2F5104A2331312B7ABF67_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableVectorToIListAdapter_System_Collections_IList_RemoveAt_mDB563D51E1A4C660A1D478BCCA79101E54C71940_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableVectorToIListAdapter_System_Collections_IList_get_Item_m129A817126C8790DAC3FD3B5E956068FCBBCB1E4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IBindableVectorToIListAdapter_System_Collections_IList_set_Item_mEFAB5281F54A55D59E9225F3089D6DF7F20CB7D1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IInspectableToICollectionAdapter_System_Collections_ICollection_CopyTo_m5B1BF0A28E3D8FA85129960EDA360A0EEC407288_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IInspectableToICollectionAdapter_System_Collections_ICollection_get_Count_mE39C0DFD459AC768ADF3FD088A3FD3F35DF07D0C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* IInspectableToICollectionAdapter_System_Collections_IEnumerable_GetEnumerator_m5647A4B5343DC06AADD7E88669B2E8D2D9FB2288_RuntimeMethod_var;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;
struct IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F;
struct IBindableVectorView_tCB96F9780FD45A9A323C8212A53608C8A13784B3;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct NOVTABLE IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IBindableIterable_First_mE23AC28EC9ADCDD2688247217CF40C800E780B97(IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F** comReturnValue) = 0;
};
struct NOVTABLE IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IBindableIterator_get_Current_m9E2CB8A2F96597D1F54CC06773573F9A1FCBCED7(Il2CppIInspectable** comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IBindableIterator_get_HasCurrent_mDC2557A16CF0E2D863DFAF5844D47960666C6173(bool* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IBindableIterator_MoveNext_mDD60F91942359E635F8E8005E34DB61C07434D82(bool* comReturnValue) = 0;
};
struct NOVTABLE IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IBindableVector_GetAt_mBCD1ADF8844CDBB36A56C8CD9391067180851BD9(uint32_t ___0_index, Il2CppIInspectable** comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IBindableVector_get_Size_m835757C5C2780FB18C73A2D34B0C74CB9C24FAC6(uint32_t* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IBindableVector_GetView_m0EDD4048AE0A3404A66AD7202161F560DEE9D87F(IBindableVectorView_tCB96F9780FD45A9A323C8212A53608C8A13784B3** comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IBindableVector_IndexOf_m6EA6FC052533AB43E049ECDFE20789943A798907(Il2CppIInspectable* ___0_value, uint32_t* ___1_index, bool* comReturnValue) = 0;
	virtual il2cpp_hresult_t STDCALL IBindableVector_SetAt_m288413F2AE9C2F853898187EF0F0E5087FD934D0(uint32_t ___0_index, Il2CppIInspectable* ___1_value) = 0;
	virtual il2cpp_hresult_t STDCALL IBindableVector_InsertAt_m919BCD142F2F5F1CBD4ABCB9E94113B65C79D431(uint32_t ___0_index, Il2CppIInspectable* ___1_value) = 0;
	virtual il2cpp_hresult_t STDCALL IBindableVector_RemoveAt_m54B727C7320AF1552F630DD4E98DCD7D3CB04538(uint32_t ___0_index) = 0;
	virtual il2cpp_hresult_t STDCALL IBindableVector_Append_mAC3F455B05DB32D9681767CD442DEACE2EE7348E(Il2CppIInspectable* ___0_value) = 0;
	virtual il2cpp_hresult_t STDCALL IBindableVector_RemoveAtEnd_mD4F1D0442F5A0A74C29E5DBCAFB1BFF14E40FC71() = 0;
	virtual il2cpp_hresult_t STDCALL IBindableVector_Clear_m3353A716402EE8270D6D3F2A02863714D7787B7C() = 0;
};
struct NOVTABLE IClosable_t408735E2F18F562F8A87A4C359E73D7C30A1D301 : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IClosable_Close_mCB0DF137CDDDCC22063CF8D95ECE3BC9B8FA0D88() = 0;
};
struct NOVTABLE IStringable_t0AFBCE43502CD93D1B4A1CC7F34AC6C3E260D434 : Il2CppIInspectable
{
	static const Il2CppGuid IID;
	virtual il2cpp_hresult_t STDCALL IStringable_ToString_m9EC5E77A3DC98527557A6F8D901B8045C3BBD8B2(Il2CppHString* comReturnValue) = 0;
};
struct IBindableIterableToIEnumerableAdapter_t8388E8C2838435C66EE4B1B25C5D7BA613F5E062  : public RuntimeObject
{
};
struct IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A  : public RuntimeObject
{
	RuntimeObject* ___iterator;
	bool ___initialized;
	bool ___hadCurrent;
	RuntimeObject* ___current;
};
struct IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C  : public RuntimeObject
{
};
struct IClosableToIDisposableAdapter_tD6218CE13709C28F778EE324FAF6DC9799DFEE7D  : public RuntimeObject
{
};
struct IInspectableToICollectionAdapter_t79A837B414D58B2BDA9B2AC57925247E5A3F982E  : public RuntimeObject
{
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
struct __Il2CppComDelegate_tD0DD2BBA6AC8F151D32B6DFD02F6BDA339F8DC4D  : public Il2CppComObject
{
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
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
struct SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295  : public Exception_t
{
};
struct ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
	String_t* ____paramName;
};
struct InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A  : public SystemException_tCC48D868298F4C0705279823E34B00F4FBDB7295
{
};
struct ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
};
struct ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F  : public ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263
{
	RuntimeObject* ____actualValue;
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
struct Exception_t_StaticFields
{
	RuntimeObject* ___s_EDILock;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif



IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Object_ToString_mF8AC1EB9D85AB52EC8FD8B8BDD131E855E69673F (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void __Il2CppComObject_Finalize_m720B2062F661A0770A32D24B731AD4AFE314A5CD (Il2CppComObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Marshal_GetHRForException_mC95F09D3FC1FD327CC2DA68234F769E20FC5D5D9 (Exception_t* ___0_e, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162 (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IBindableIteratorToIEnumeratorAdapter__ctor_m8011BCA550C98E8CDA742DC18A29CFBE0533172F (IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A* __this, RuntimeObject* ___0_iterator, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Exception_get_HResult_mBA9CD3C01C2F0C68DFA6ED7824F7371D7E1A4163_inline (Exception_t* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* __this, String_t* ___0_paramName, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465 (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* __this, String_t* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_SetValue_mE9507B366ED84E91E92BF32649D36916F96C67B8 (RuntimeArray* __this, RuntimeObject* ___0_value, int32_t ___1_index, const RuntimeMethod* method) ;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void __Il2CppComObject_Finalize_m720B2062F661A0770A32D24B731AD4AFE314A5CD (Il2CppComObject* __this, const RuntimeMethod* method) 
{
	if (__this->identity != NULL)
	{
		il2cpp_codegen_il2cpp_com_object_cleanup(__this);
		__this->identity->Release();
		__this->identity = NULL;
	}

	Object_Finalize_mC98C96301CCABFE00F1A7EF8E15DF507CACD42B2(__this, NULL);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* __Il2CppComObject_ToString_mE59B6B57070423F4E533C3C99B309434F79F132A (Il2CppComObject* __this, const RuntimeMethod* method) 
{
	IStringable_t0AFBCE43502CD93D1B4A1CC7F34AC6C3E260D434* ____istringable_t0AFBCE43502CD93D1B4A1CC7F34AC6C3E260D434 = il2cpp_codegen_com_query_interface_no_throw<IStringable_t0AFBCE43502CD93D1B4A1CC7F34AC6C3E260D434>(__this);
	if (____istringable_t0AFBCE43502CD93D1B4A1CC7F34AC6C3E260D434 != NULL)
	{
		Il2CppHString returnValue = NULL;
		const il2cpp_hresult_t hr = ____istringable_t0AFBCE43502CD93D1B4A1CC7F34AC6C3E260D434->IStringable_ToString_m9EC5E77A3DC98527557A6F8D901B8045C3BBD8B2(&returnValue);

		il2cpp_codegen_com_raise_exception_if_failed(hr, false);

		String_t* _returnValue_unmarshaled = NULL;
		_returnValue_unmarshaled = il2cpp_codegen_marshal_hstring_result(returnValue);

		il2cpp_codegen_marshal_free_hstring(returnValue);
		returnValue = NULL;

		return _returnValue_unmarshaled;
	}
	String_t* toStringRetVal;
	toStringRetVal = Object_ToString_mF8AC1EB9D85AB52EC8FD8B8BDD131E855E69673F(__this, NULL);
	return toStringRetVal;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void __Il2CppComDelegate_Finalize_mC9F8EA94444C3AF0A43CC723A23EE4D8B7984F8C (__Il2CppComDelegate_tD0DD2BBA6AC8F151D32B6DFD02F6BDA339F8DC4D* __this, const RuntimeMethod* method) 
{
	__Il2CppComObject_Finalize_m720B2062F661A0770A32D24B731AD4AFE314A5CD(__this, NULL);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
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
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IBindableIteratorToIEnumeratorAdapter_System_Collections_IEnumerator_MoveNext_mDAD00541F5B2D7652EDD9B31C6AF884783219F55 (IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		bool L_0 = __this->___hadCurrent;
		if (L_0)
		{
			goto IL_000a;
		}
	}
	{
		return (bool)0;
	}

IL_000a:
	try
	{

IL_000a_1:
		{
			bool L_1 = __this->___initialized;
			if (L_1)
			{
				goto IL_002c_1;
			}
		}
		{
			RuntimeObject* L_2 = __this->___iterator;
			NullCheck(L_2);
			bool L_3;
			L_3 = InterfaceFuncInvoker0< bool >::Invoke(1, IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F_il2cpp_TypeInfo_var, L_2);
			__this->___hadCurrent = L_3;
			__this->___initialized = (bool)1;
			goto IL_003d_1;
		}

IL_002c_1:
		{
			RuntimeObject* L_4 = __this->___iterator;
			NullCheck(L_4);
			bool L_5;
			L_5 = InterfaceFuncInvoker0< bool >::Invoke(2, IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F_il2cpp_TypeInfo_var, L_4);
			__this->___hadCurrent = L_5;
		}

IL_003d_1:
		{
			bool L_6 = __this->___hadCurrent;
			if (!L_6)
			{
				goto IL_0056_1;
			}
		}
		{
			RuntimeObject* L_7 = __this->___iterator;
			NullCheck(L_7);
			RuntimeObject* L_8;
			L_8 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IBindableIterator_t63CCD2268CEE8AFAB68518869D47C5BDAF72962F_il2cpp_TypeInfo_var, L_7);
			__this->___current = L_8;
			Il2CppCodeGenWriteBarrier((void**)(&__this->___current), (void*)L_8);
		}

IL_0056_1:
		{
			goto IL_0071;
		}
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0058;
		}
		throw e;
	}

CATCH_0058:
	{
		{
			il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Marshal_tD976A56A90263C3CE2B780D4B1CADADE2E70B4A7_il2cpp_TypeInfo_var)));
			int32_t L_9;
			L_9 = Marshal_GetHRForException_mC95F09D3FC1FD327CC2DA68234F769E20FC5D5D9(((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*)), NULL);
			if ((!(((uint32_t)L_9) == ((uint32_t)((int32_t)-2147483636)))))
			{
				goto IL_006f;
			}
		}
		{
			InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_10 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
			InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_10, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralF8D08FCF1537043BF0289FA98C51BF5A3AC7C618)), NULL);
			IL2CPP_RAISE_MANAGED_EXCEPTION(L_10, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableIteratorToIEnumeratorAdapter_System_Collections_IEnumerator_MoveNext_mDAD00541F5B2D7652EDD9B31C6AF884783219F55_RuntimeMethod_var)));
		}

IL_006f:
		{
			IL2CPP_RETHROW_MANAGED_EXCEPTION(IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));
		}
	}

IL_0071:
	{
		bool L_11 = __this->___hadCurrent;
		return L_11;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* IBindableIteratorToIEnumeratorAdapter_System_Collections_IEnumerator_get_Current_mCD38EF40228F1C884E89C162679AC9C96FAD3482 (IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___initialized;
		if (L_0)
		{
			goto IL_0013;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_1 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2390D6884F59E2E4EA04837AD7D6268548597633)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableIteratorToIEnumeratorAdapter_System_Collections_IEnumerator_get_Current_mCD38EF40228F1C884E89C162679AC9C96FAD3482_RuntimeMethod_var)));
	}

IL_0013:
	{
		bool L_2 = __this->___hadCurrent;
		if (L_2)
		{
			goto IL_0026;
		}
	}
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_3 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral834F4B6837B71847C4048C946DF8754B323D6BF9)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableIteratorToIEnumeratorAdapter_System_Collections_IEnumerator_get_Current_mCD38EF40228F1C884E89C162679AC9C96FAD3482_RuntimeMethod_var)));
	}

IL_0026:
	{
		RuntimeObject* L_4 = __this->___current;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IBindableIteratorToIEnumeratorAdapter_System_Collections_IEnumerator_Reset_mAA1156ED1002B068A4D650A4A8299EDC9BD9AE8E (IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_m1398D0CDE19B36AA3DE9392879738C1EA2439CDF(L_0, NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableIteratorToIEnumeratorAdapter_System_Collections_IEnumerator_Reset_mAA1156ED1002B068A4D650A4A8299EDC9BD9AE8E_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IBindableIteratorToIEnumeratorAdapter__ctor_m8011BCA550C98E8CDA742DC18A29CFBE0533172F (IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A* __this, RuntimeObject* ___0_iterator, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		RuntimeObject* L_0 = ___0_iterator;
		__this->___iterator = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___iterator), (void*)L_0);
		__this->___hadCurrent = (bool)1;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IClosableToIDisposableAdapter_System_IDisposable_Dispose_m501D14E26D43BC46FBBCFF4F120599F5C6646641 (IClosableToIDisposableAdapter_tD6218CE13709C28F778EE324FAF6DC9799DFEE7D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IClosable_t408735E2F18F562F8A87A4C359E73D7C30A1D301_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		InterfaceActionInvoker0::Invoke(0, IClosable_t408735E2F18F562F8A87A4C359E73D7C30A1D301_il2cpp_TypeInfo_var, __this);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* IBindableIterableToIEnumerableAdapter_System_Collections_IEnumerable_GetEnumerator_mCCE38984D99C58AE3315B728940CF99D4B1E8A88 (IBindableIterableToIEnumerableAdapter_t8388E8C2838435C66EE4B1B25C5D7BA613F5E062* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	{
		RuntimeObject* L_0;
		L_0 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IBindableIterable_t257967EF5CDA5DFD63615802571892212B01796C_il2cpp_TypeInfo_var, __this);
		RuntimeObject* L_1 = L_0;
		V_0 = L_1;
		if (L_1)
		{
			goto IL_000f;
		}
	}
	{
		return (RuntimeObject*)NULL;
	}

IL_000f:
	{
		RuntimeObject* L_2 = V_0;
		IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A* L_3 = (IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A*)il2cpp_codegen_object_new(IBindableIteratorToIEnumeratorAdapter_t01B2469E85CA1147A3E2BE2C90AD129D6427409A_il2cpp_TypeInfo_var);
		IBindableIteratorToIEnumeratorAdapter__ctor_m8011BCA550C98E8CDA742DC18A29CFBE0533172F(L_3, L_2, NULL);
		return L_3;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* IBindableVectorToIListAdapter_System_Collections_IList_get_Item_m129A817126C8790DAC3FD3B5E956068FCBBCB1E4 (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) < ((int32_t)0)))
		{
			goto IL_0026;
		}
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2;
		L_2 = InterfaceFuncInvoker1< RuntimeObject*, uint32_t >::Invoke(0, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this, L_1);
		return L_2;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0015;
		}
		throw e;
	}

CATCH_0015:
	{
		{
			NullCheck(((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*)));
			int32_t L_3;
			L_3 = Exception_get_HResult_mBA9CD3C01C2F0C68DFA6ED7824F7371D7E1A4163_inline(((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*)), NULL);
			if ((((int32_t)L_3) == ((int32_t)((int32_t)-2147483637))))
			{
				goto IL_0026;
			}
		}
		{
			IL2CPP_RETHROW_MANAGED_EXCEPTION(IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));
		}
	}

IL_0026:
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableVectorToIListAdapter_System_Collections_IList_get_Item_m129A817126C8790DAC3FD3B5E956068FCBBCB1E4_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IBindableVectorToIListAdapter_System_Collections_IList_set_Item_mEFAB5281F54A55D59E9225F3089D6DF7F20CB7D1 (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) < ((int32_t)0)))
		{
			goto IL_002a;
		}
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		InterfaceActionInvoker2< uint32_t, RuntimeObject* >::Invoke(4, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this, L_1, L_2);
		return;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0019;
		}
		throw e;
	}

CATCH_0019:
	{
		{
			NullCheck(((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*)));
			int32_t L_3;
			L_3 = Exception_get_HResult_mBA9CD3C01C2F0C68DFA6ED7824F7371D7E1A4163_inline(((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*)), NULL);
			if ((((int32_t)L_3) == ((int32_t)((int32_t)-2147483637))))
			{
				goto IL_002a;
			}
		}
		{
			IL2CPP_RETHROW_MANAGED_EXCEPTION(IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));
		}
	}

IL_002a:
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableVectorToIListAdapter_System_Collections_IList_set_Item_mEFAB5281F54A55D59E9225F3089D6DF7F20CB7D1_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t IBindableVectorToIListAdapter_System_Collections_IList_Add_m6C7CD5678799665F6708A3E5A0BCF6BE0DF8B3FC (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = ___0_value;
		InterfaceActionInvoker1< RuntimeObject* >::Invoke(7, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this, L_0);
		int32_t L_1;
		L_1 = InterfaceFuncInvoker0< int32_t >::Invoke(1, ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E_il2cpp_TypeInfo_var, __this);
		return ((int32_t)il2cpp_codegen_subtract(L_1, 1));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IBindableVectorToIListAdapter_System_Collections_IList_Contains_m04B684FF9B345C50FFFDEEB53B5937957216B858 (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	uint32_t V_1 = 0;
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = InterfaceFuncInvoker2< bool, RuntimeObject*, uint32_t* >::Invoke(3, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this, L_0, (&V_1));
		V_0 = L_1;
		bool L_2 = V_0;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IBindableVectorToIListAdapter_System_Collections_IList_Clear_m47FADB41672A2524DC51D8181BA8277A99E4748F (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		InterfaceActionInvoker0::Invoke(9, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IBindableVectorToIListAdapter_System_Collections_IList_get_IsReadOnly_mD10F9C91D25699BE580ED80C4463CB8860503390 (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IBindableVectorToIListAdapter_System_Collections_IList_get_IsFixedSize_m6E688304BE3EEBD22E29AA8852030FE63E4CAD2E (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t IBindableVectorToIListAdapter_System_Collections_IList_IndexOf_m6F630822791D1DC1303F642621EFB684CB1F8BC1 (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	uint32_t V_0 = 0;
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = InterfaceFuncInvoker2< bool, RuntimeObject*, uint32_t* >::Invoke(3, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this, L_0, (&V_0));
		if (L_1)
		{
			goto IL_0012;
		}
	}
	{
		return (-1);
	}

IL_0012:
	{
		uint32_t L_2 = V_0;
		if ((!(((uint32_t)L_2) <= ((uint32_t)((int32_t)2147483647LL)))))
		{
			goto IL_0026;
		}
	}
	{
		uint32_t L_3 = V_0;
		return L_3;
	}

IL_0026:
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_4 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE6200FC24048842D4802BFB4F92BEE9C12FE7A9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableVectorToIListAdapter_System_Collections_IList_IndexOf_m6F630822791D1DC1303F642621EFB684CB1F8BC1_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IBindableVectorToIListAdapter_System_Collections_IList_Insert_m88FA248F41D748BB6DF2F5104A2331312B7ABF67 (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, int32_t ___0_index, RuntimeObject* ___1_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) < ((int32_t)0)))
		{
			goto IL_002a;
		}
	}
	try
	{
		int32_t L_1 = ___0_index;
		RuntimeObject* L_2 = ___1_value;
		InterfaceActionInvoker2< uint32_t, RuntimeObject* >::Invoke(5, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this, L_1, L_2);
		return;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0019;
		}
		throw e;
	}

CATCH_0019:
	{
		{
			NullCheck(((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*)));
			int32_t L_3;
			L_3 = Exception_get_HResult_mBA9CD3C01C2F0C68DFA6ED7824F7371D7E1A4163_inline(((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*)), NULL);
			if ((((int32_t)L_3) == ((int32_t)((int32_t)-2147483637))))
			{
				goto IL_002a;
			}
		}
		{
			IL2CPP_RETHROW_MANAGED_EXCEPTION(IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));
		}
	}

IL_002a:
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_4 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_4, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_4, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableVectorToIListAdapter_System_Collections_IList_Insert_m88FA248F41D748BB6DF2F5104A2331312B7ABF67_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IBindableVectorToIListAdapter_System_Collections_IList_Remove_mEF5B163046A0BCCC4F032F21B14A856723AA5C2E (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	uint32_t V_0 = 0;
	{
		RuntimeObject* L_0 = ___0_value;
		bool L_1;
		L_1 = InterfaceFuncInvoker2< bool, RuntimeObject*, uint32_t* >::Invoke(3, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this, L_0, (&V_0));
		if (!L_1)
		{
			goto IL_001a;
		}
	}
	{
		uint32_t L_2 = V_0;
		InterfaceActionInvoker1< uint32_t >::Invoke(6, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this, L_2);
	}

IL_001a:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IBindableVectorToIListAdapter_System_Collections_IList_RemoveAt_mDB563D51E1A4C660A1D478BCCA79101E54C71940 (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, int32_t ___0_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	{
		int32_t L_0 = ___0_index;
		if ((((int32_t)L_0) < ((int32_t)0)))
		{
			goto IL_0026;
		}
	}
	try
	{
		int32_t L_1 = ___0_index;
		InterfaceActionInvoker1< uint32_t >::Invoke(6, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this, L_1);
		return;
	}
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0015;
		}
		throw e;
	}

CATCH_0015:
	{
		{
			NullCheck(((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*)));
			int32_t L_2;
			L_2 = Exception_get_HResult_mBA9CD3C01C2F0C68DFA6ED7824F7371D7E1A4163_inline(((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*)), NULL);
			if ((((int32_t)L_2) == ((int32_t)((int32_t)-2147483637))))
			{
				goto IL_0026;
			}
		}
		{
			IL2CPP_RETHROW_MANAGED_EXCEPTION(IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));
		}
	}

IL_0026:
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_3 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableVectorToIListAdapter_System_Collections_IList_RemoveAt_mDB563D51E1A4C660A1D478BCCA79101E54C71940_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IBindableVectorToIListAdapter_System_Collections_ICollection_CopyTo_m2CDA4A8C4FCA77BE2594E6E6F749A1A74FAA0312 (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral893C6A70E6986916540A62EB89DF7EE2457D3DC8)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableVectorToIListAdapter_System_Collections_ICollection_CopyTo_m2CDA4A8C4FCA77BE2594E6E6F749A1A74FAA0312_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t IBindableVectorToIListAdapter_System_Collections_ICollection_get_Count_m845690015DDDE5D20B2E7DA2377A36F0DFD89BC5 (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral601864F27855188434B3BC9664592B159BD53FA6)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableVectorToIListAdapter_System_Collections_ICollection_get_Count_m845690015DDDE5D20B2E7DA2377A36F0DFD89BC5_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* IBindableVectorToIListAdapter_System_Collections_ICollection_get_SyncRoot_m7600DD62C4B3CEBDBE7258CAF93503BB2D8ABDD8 (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralC67981104B030F2C9B107A0F7873A4F201E95009)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableVectorToIListAdapter_System_Collections_ICollection_get_SyncRoot_m7600DD62C4B3CEBDBE7258CAF93503BB2D8ABDD8_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IBindableVectorToIListAdapter_System_Collections_ICollection_get_IsSynchronized_mEC643873CFA92251AF8E8C346B358D4E9BACFAAE (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralD1EB4ADB9F8DAF79365F268B73404FB4E6318BCC)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableVectorToIListAdapter_System_Collections_ICollection_get_IsSynchronized_mEC643873CFA92251AF8E8C346B358D4E9BACFAAE_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* IBindableVectorToIListAdapter_System_Collections_IEnumerable_GetEnumerator_mDAF2E67C36C34579822F83A90B36CBB09D7247CC (IBindableVectorToIListAdapter_t6040089CB3FFA61B3AEB770DE5085DA9D57D805C* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral94046C5588508CC292E2C8D101FD4A30B1AA35FE)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IBindableVectorToIListAdapter_System_Collections_IEnumerable_GetEnumerator_mDAF2E67C36C34579822F83A90B36CBB09D7247CC_RuntimeMethod_var)));
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IInspectableToICollectionAdapter_System_Collections_ICollection_CopyTo_m5B1BF0A28E3D8FA85129960EDA360A0EEC407288 (IInspectableToICollectionAdapter_t79A837B414D58B2BDA9B2AC57925247E5A3F982E* __this, RuntimeArray* ___0_array, int32_t ___1_index, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	int32_t V_1 = 0;
	{
		RuntimeArray* L_0 = ___0_array;
		if (L_0)
		{
			goto IL_0011;
		}
	}
	{
		ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129* L_1 = (ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentNullException_t327031E412FAB2351B0022DD5DAD47E67E597129_il2cpp_TypeInfo_var)));
		ArgumentNullException__ctor_m444AE141157E333844FC1A9500224C2F9FD24F4B(L_1, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralB829404B947F7E1629A30B5E953A49EB21CCD2ED)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_1, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IInspectableToICollectionAdapter_System_Collections_ICollection_CopyTo_m5B1BF0A28E3D8FA85129960EDA360A0EEC407288_RuntimeMethod_var)));
	}

IL_0011:
	{
		int32_t L_2 = ___1_index;
		if ((((int32_t)L_2) >= ((int32_t)0)))
		{
			goto IL_0024;
		}
	}
	{
		ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F* L_3 = (ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentOutOfRangeException_tEA2822DAF62B10EEED00E0E3A341D4BAF78CF85F_il2cpp_TypeInfo_var)));
		ArgumentOutOfRangeException__ctor_mBC1D5DEEA1BA41DE77228CB27D6BAFEB6DCCBF4A(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral2B6D6F48C27C60C3B55391AB377D9DC8F5639AA1)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IInspectableToICollectionAdapter_System_Collections_ICollection_CopyTo_m5B1BF0A28E3D8FA85129960EDA360A0EEC407288_RuntimeMethod_var)));
	}

IL_0024:
	{
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(1, ICollection_t37E7B9DC5B4EF41D190D607F92835BF1171C0E8E_il2cpp_TypeInfo_var, __this);
		V_1 = L_4;
		int32_t L_5 = V_1;
		if (L_5)
		{
			goto IL_0039;
		}
	}
	{
		return;
	}

IL_0039:
	{
		int32_t L_6 = ___1_index;
		RuntimeArray* L_7 = ___0_array;
		NullCheck(L_7);
		if ((((int32_t)L_6) < ((int32_t)(((RuntimeArray*)L_7)->max_length))))
		{
			goto IL_004d;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_8 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_8, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralDA70662AC1619107177B004460D78346FFAE295D)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_8, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IInspectableToICollectionAdapter_System_Collections_ICollection_CopyTo_m5B1BF0A28E3D8FA85129960EDA360A0EEC407288_RuntimeMethod_var)));
	}

IL_004d:
	{
		RuntimeArray* L_9 = ___0_array;
		NullCheck(L_9);
		int32_t L_10 = V_1;
		int32_t L_11 = ___1_index;
		if ((((int32_t)((int32_t)il2cpp_codegen_subtract((int32_t)(((RuntimeArray*)L_9)->max_length), L_10))) >= ((int32_t)L_11)))
		{
			goto IL_0066;
		}
	}
	{
		ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263* L_12 = (ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ArgumentException_tAD90411542A20A9C72D5CDA3A84181D8B947A263_il2cpp_TypeInfo_var)));
		ArgumentException__ctor_m026938A67AF9D36BB7ED27F80425D7194B514465(L_12, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral18E7747DF396126C8F06504578145283EC80CCE2)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_12, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IInspectableToICollectionAdapter_System_Collections_ICollection_CopyTo_m5B1BF0A28E3D8FA85129960EDA360A0EEC407288_RuntimeMethod_var)));
	}

IL_0066:
	{
		RuntimeObject* L_13;
		L_13 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_t6331596D5DD37C462B1B8D49CF6B319B00AB7131_il2cpp_TypeInfo_var, __this);
		V_0 = L_13;
	}

IL_0071:
	{
		RuntimeObject* L_14 = V_0;
		NullCheck(L_14);
		bool L_15;
		L_15 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_14);
		if (!L_15)
		{
			goto IL_009c;
		}
	}
	{
		RuntimeArray* L_16 = ___0_array;
		RuntimeObject* L_17 = V_0;
		NullCheck(L_17);
		RuntimeObject* L_18;
		L_18 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(1, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_17);
		int32_t L_19 = ___1_index;
		int32_t L_20 = L_19;
		___1_index = ((int32_t)il2cpp_codegen_add(L_20, 1));
		NullCheck(L_16);
		Array_SetValue_mE9507B366ED84E91E92BF32649D36916F96C67B8(L_16, L_18, L_20, NULL);
		goto IL_0071;
	}

IL_009c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t IInspectableToICollectionAdapter_System_Collections_ICollection_get_Count_mE39C0DFD459AC768ADF3FD088A3FD3F35DF07D0C (IInspectableToICollectionAdapter_t79A837B414D58B2BDA9B2AC57925247E5A3F982E* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	{
		uint32_t L_0;
		L_0 = InterfaceFuncInvoker0< uint32_t >::Invoke(1, IBindableVector_tAE2FC72291BFE4E2FE6FCE88670236BBA429833A_il2cpp_TypeInfo_var, __this);
		V_0 = L_0;
		int32_t L_1 = V_0;
		if ((!(((uint32_t)L_1) < ((uint32_t)((int32_t)2147483647LL)))))
		{
			goto IL_001a;
		}
	}
	{
		int32_t L_2 = V_0;
		return L_2;
	}

IL_001a:
	{
		InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB* L_3 = (InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&InvalidOperationException_t5DDE4D49B7405FAAB1E4576F4715A42A3FAD4BAB_il2cpp_TypeInfo_var)));
		InvalidOperationException__ctor_mE4CB6F4712AB6D99A2358FBAE2E052B3EE976162(L_3, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralE6200FC24048842D4802BFB4F92BEE9C12FE7A9E)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_3, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IInspectableToICollectionAdapter_System_Collections_ICollection_get_Count_mE39C0DFD459AC768ADF3FD088A3FD3F35DF07D0C_RuntimeMethod_var)));
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* IInspectableToICollectionAdapter_System_Collections_ICollection_get_SyncRoot_m4AF4874507B5A49EE33359A4C018A28B7FF603D3 (IInspectableToICollectionAdapter_t79A837B414D58B2BDA9B2AC57925247E5A3F982E* __this, const RuntimeMethod* method) 
{
	{
		return __this;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IInspectableToICollectionAdapter_System_Collections_ICollection_get_IsSynchronized_m26B262315DF57075A12C34A6A6134FE9B66872F0 (IInspectableToICollectionAdapter_t79A837B414D58B2BDA9B2AC57925247E5A3F982E* __this, const RuntimeMethod* method) 
{
	{
		return (bool)0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* IInspectableToICollectionAdapter_System_Collections_IEnumerable_GetEnumerator_m5647A4B5343DC06AADD7E88669B2E8D2D9FB2288 (IInspectableToICollectionAdapter_t79A837B414D58B2BDA9B2AC57925247E5A3F982E* __this, const RuntimeMethod* method) 
{
	{
		NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A* L_0 = (NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A*)il2cpp_codegen_object_new(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&NotSupportedException_t1429765983D409BD2986508963C98D214E4EBF4A_il2cpp_TypeInfo_var)));
		NotSupportedException__ctor_mE174750CF0247BBB47544FFD71D66BB89630945B(L_0, ((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral94FD93033ADDABB82341E25C5060807B4D72DE0B)), NULL);
		IL2CPP_RAISE_MANAGED_EXCEPTION(L_0, ((RuntimeMethod*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&IInspectableToICollectionAdapter_System_Collections_IEnumerable_GetEnumerator_m5647A4B5343DC06AADD7E88669B2E8D2D9FB2288_RuntimeMethod_var)));
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t Exception_get_HResult_mBA9CD3C01C2F0C68DFA6ED7824F7371D7E1A4163_inline (Exception_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____HResult;
		return L_0;
	}
}
