#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


struct VirtualActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
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
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
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
template <typename R>
struct GenericVirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (const RuntimeMethod* method, RuntimeObject* obj)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_virtual_invoke_data(method, obj, &invokeData);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
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

struct Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83;
struct Dictionary_2_t18E076B12814DFAAD91B5BC1B163AAFAC0CADEFD;
struct IReadOnlyList_1_t2B96B7FE2C44634D70F69C777077D230700AD798;
struct List_1_tADF7F1C5FADE0AE6D00BC928B20C4B63DDC8A3AD;
struct List_1_t51E625EDA46926814063BAC38407B110D9C48805;
struct List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B;
struct List_1_t750037577EF626FCB1112EA42C03AB4CCF7974E7;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct MixedRealitySpatialObserverConfigurationU5BU5D_t175B52CA1DE4DF781F77F7FAF9566C4FC8A83884;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct BaseCoreSystem_t9D02F9BBC05DAD6F987F647B666B37A062ACFAA6;
struct BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2;
struct BaseEventSystem_tB9BD9711D545EEEF00D3162ED9A13EBDE4B1DEA1;
struct BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4;
struct BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0;
struct BaseSpatialAwarenessObserverProfile_t7A50E95DBFF01391175C2D418C1ABB3C21F43225;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
struct IMixedRealityServiceRegistrar_t4B893B7CDAAC977211D826D02C8522ECA327D715;
struct IMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90;
struct MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7;
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
struct String_t;
struct SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E;
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1;
struct Type_t;
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_t6B10F3A424EFE01ACD974D0593A4D0B3AD91B280;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* Application_tDB03BE91CDF0ACA614A5E0B67CFB77C44EB19B21_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMixedRealityCapabilityCheck_t89E15A80CA84BBA26759BE2D8A2720CD26534921_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IReadOnlyCollection_1_t04A6836A5829DBDAAF26CD938058299A14B25033_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IReadOnlyList_1_t2B96B7FE2C44634D70F69C777077D230700AD798_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_t2A6E257BA7214B78EB1995BCD4C6C9FFAE5163C8____0BBB3F47A68A9B10B62A23498D1B4EB5C90D63AFBB2BD20DAAF42DE66F9BA86C_FieldInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_t2A6E257BA7214B78EB1995BCD4C6C9FFAE5163C8____9F273D8B81B87B2FAEF4653458E76AF589A4D75D16BD4B77595C93F0D8FEB888_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral0755F3DCD1C7D7F8C7F146B5C1598C86897222FA;
IL2CPP_EXTERN_C String_t* _stringLiteral1493973E273A553C92B106E28BD722E4E3A0AD98;
IL2CPP_EXTERN_C String_t* _stringLiteral188D30B6EDF85BA42D4E192BE1E93A4D2142FDCB;
IL2CPP_EXTERN_C String_t* _stringLiteral3AF268028A7C8D24E1A3278EC06A941AF3AB7C83;
IL2CPP_EXTERN_C String_t* _stringLiteral474447FAD0D27BF6A99C1C7093B70018F15EE835;
IL2CPP_EXTERN_C String_t* _stringLiteral56EB1B275FCFAC7E81FE874CCF19B184937C1493;
IL2CPP_EXTERN_C String_t* _stringLiteral5C25A67358FA149F467647A046B5549855D72011;
IL2CPP_EXTERN_C String_t* _stringLiteral72F7A6E2A6DE3E5DE76E40BC176AD33FCE86E0A7;
IL2CPP_EXTERN_C String_t* _stringLiteral80B8FC02531D63146A2F2DE67A3DC123891215FC;
IL2CPP_EXTERN_C String_t* _stringLiteral84210E916B771570003864C57344196A52266B35;
IL2CPP_EXTERN_C String_t* _stringLiteral91B3ABEA5982C1F945523544B3BA94100AE5F5DB;
IL2CPP_EXTERN_C String_t* _stringLiteralB612C75ADB2AE97EA4EA097D17EA7667AA2E78A8;
IL2CPP_EXTERN_C String_t* _stringLiteralBEF51D8BFDF5409F7D7A407464E210AB7AF45304;
IL2CPP_EXTERN_C String_t* _stringLiteralC4149992C36FE958949693FAE84EE89309D872FA;
IL2CPP_EXTERN_C String_t* _stringLiteralC51718E69592BF754ED468BA0E33592D41CC0711;
IL2CPP_EXTERN_C String_t* _stringLiteralD7A0E2B84A2188BA28341150550C337C542E8671;
IL2CPP_EXTERN_C const RuntimeMethod* BaseDataProviderAccessCoreSystem_RegisterDataProvider_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_m1BAF0E595E77E9EA59C6B8FCA6D7B86833DB0D68_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseDataProviderAccessCoreSystem_UnregisterDataProvider_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mCD9464EB917CF367BD8BA93B24804467C4533CF1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct MixedRealitySpatialObserverConfigurationU5BU5D_t175B52CA1DE4DF781F77F7FAF9566C4FC8A83884;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CModuleU3E_t46C957EFB48F4CBC869F0E76D5BC2DA8EF8E5421 
{
};
struct U3CPrivateImplementationDetailsU3E_t2A6E257BA7214B78EB1995BCD4C6C9FFAE5163C8  : public RuntimeObject
{
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E  : public RuntimeObject
{
	String_t* ___reference;
	Type_t* ___type;
};
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_t6B10F3A424EFE01ACD974D0593A4D0B3AD91B280  : public RuntimeObject
{
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
struct Nullable_1_t78F453FADB4A9F50F267A4E349019C34410D1A01 
{
	bool ___hasValue;
	bool ___value;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3 
{
	uint8_t ___m_value;
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75 
{
	SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E* ___componentType;
	String_t* ___componentName;
	uint32_t ___priority;
	int32_t ___runtimePlatform;
	BaseSpatialAwarenessObserverProfile_t7A50E95DBFF01391175C2D418C1ABB3C21F43225* ___observerProfile;
};
struct MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75_marshaled_pinvoke
{
	SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E* ___componentType;
	char* ___componentName;
	uint32_t ___priority;
	int32_t ___runtimePlatform;
	BaseSpatialAwarenessObserverProfile_t7A50E95DBFF01391175C2D418C1ABB3C21F43225* ___observerProfile;
};
struct MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75_marshaled_com
{
	SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E* ___componentType;
	Il2CppChar* ___componentName;
	uint32_t ___priority;
	int32_t ___runtimePlatform;
	BaseSpatialAwarenessObserverProfile_t7A50E95DBFF01391175C2D418C1ABB3C21F43225* ___observerProfile;
};
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	uint16_t ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	float ___x;
	float ___y;
	float ___z;
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
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D158_t2391922CBDC7D28F7FAF3CC35BE36B6DDE909610 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D158_t2391922CBDC7D28F7FAF3CC35BE36B6DDE909610__padding[158];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D87_t0076ACD3EEEB19992FE3A0AF37210108DD86FC9F 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D87_t0076ACD3EEEB19992FE3A0AF37210108DD86FC9F__padding[87];
	};
};
#pragma pack(pop, tp)
struct MonoScriptData_t20F4088CE66646467619047040B266DF5A437888 
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___FilePathsData;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	bool ___IsEditorOnly;
};
struct MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshaled_pinvoke
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshaled_com
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0  : public RuntimeObject
{
	String_t* ___U3CNameU3Ek__BackingField;
	uint32_t ___U3CPriorityU3Ek__BackingField;
	BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* ___U3CConfigurationProfileU3Ek__BackingField;
	Nullable_1_t78F453FADB4A9F50F267A4E349019C34410D1A01 ___isInitialized;
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___typeName;
	Nullable_1_t78F453FADB4A9F50F267A4E349019C34410D1A01 ___isEnabled;
	Nullable_1_t78F453FADB4A9F50F267A4E349019C34410D1A01 ___isMarkedDestroyed;
	bool ___disposed;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr;
};
struct ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD 
{
	intptr_t ___m_Ptr;
};
struct RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 
{
	intptr_t ___value;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 
{
	intptr_t ___m_Ptr;
};
struct BaseEventSystem_tB9BD9711D545EEEF00D3162ED9A13EBDE4B1DEA1  : public BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0
{
	int32_t ___eventExecutionDepth;
	Type_t* ___eventSystemHandlerType;
	List_1_t51E625EDA46926814063BAC38407B110D9C48805* ___postponedActions;
	List_1_tADF7F1C5FADE0AE6D00BC928B20C4B63DDC8A3AD* ___postponedObjectActions;
	Dictionary_2_t18E076B12814DFAAD91B5BC1B163AAFAC0CADEFD* ___U3CEventHandlersByTypeU3Ek__BackingField;
	List_1_tB951CE80B58D1BF9650862451D8DAD8C231F207B* ___U3CEventListenersU3Ek__BackingField;
};
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_pinvoke : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
};
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_com : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct BaseCoreSystem_t9D02F9BBC05DAD6F987F647B666B37A062ACFAA6  : public BaseEventSystem_tB9BD9711D545EEEF00D3162ED9A13EBDE4B1DEA1
{
	RuntimeObject* ___U3CRegistrarU3Ek__BackingField;
};
struct BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	bool ___isCustomProfile;
};
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};
struct BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2  : public BaseCoreSystem_t9D02F9BBC05DAD6F987F647B666B37A062ACFAA6
{
	List_1_t750037577EF626FCB1112EA42C03AB4CCF7974E7* ___dataProviders;
};
struct BaseSpatialAwarenessObserverProfile_t7A50E95DBFF01391175C2D418C1ABB3C21F43225  : public BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4
{
	int32_t ___startupBehavior;
	bool ___isStationaryObserver;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___observationExtents;
	int32_t ___observerVolumeType;
	float ___updateInterval;
};
struct MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7  : public BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4
{
	MixedRealitySpatialObserverConfigurationU5BU5D_t175B52CA1DE4DF781F77F7FAF9566C4FC8A83884* ___observerConfigurations;
};
struct MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90  : public BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2
{
	String_t* ___U3CNameU3Ek__BackingField;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___spatialAwarenessObjectParent;
	uint32_t ___nextSourceId;
	MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* ___spatialAwarenessSystemProfile;
};
struct U3CPrivateImplementationDetailsU3E_t2A6E257BA7214B78EB1995BCD4C6C9FFAE5163C8_StaticFields
{
	__StaticArrayInitTypeSizeU3D158_t2391922CBDC7D28F7FAF3CC35BE36B6DDE909610 ___0BBB3F47A68A9B10B62A23498D1B4EB5C90D63AFBB2BD20DAAF42DE66F9BA86C;
	__StaticArrayInitTypeSizeU3D87_t0076ACD3EEEB19992FE3A0AF37210108DD86FC9F ___9F273D8B81B87B2FAEF4653458E76AF589A4D75D16BD4B77595C93F0D8FEB888;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E_StaticFields
{
	Dictionary_2_t46B2DB028096FA2B828359E52F37F3105A83AD83* ___ReferenceMappings;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject;
};
struct BaseEventSystem_tB9BD9711D545EEEF00D3162ED9A13EBDE4B1DEA1_StaticFields
{
	bool ___enableDanglingHandlerDiagnostics;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___TraverseEventSystemHandlerHierarchyPerfMarker;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
struct BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2_StaticFields
{
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdatePerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___LateUpdatePerfMarker;
};
struct MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields
{
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___GetObserversPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___GetObserversTPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___GetObserverPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___GetObserverTPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___GetDataProvidersPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___GetDataProviderPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___ResumeObserversPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___ResumeObserversTPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___ResumeObserverPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___SuspendObserversPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___SuspendObserversTPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___SuspendObserverPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___ClearObservationsPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___ClearObservationsTPerfMarker;
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
struct MixedRealitySpatialObserverConfigurationU5BU5D_t175B52CA1DE4DF781F77F7FAF9566C4FC8A83884  : public RuntimeArray
{
	ALIGN_FIELD (8) MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75 m_Items[1];

	inline MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___componentType), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___componentName), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___observerProfile), (void*)NULL);
		#endif
	}
	inline MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___componentType), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___componentName), (void*)NULL);
		#endif
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___observerProfile), (void*)NULL);
		#endif
	}
};


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BaseDataProviderAccessCoreSystem_RegisterDataProvider_TisRuntimeObject_m754B4E4F42C2591B24170375FC4DD38D68679DF6_gshared (BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2* __this, Type_t* ___0_concreteType, String_t* ___1_providerName, int32_t ___2_supportedPlatforms, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___3_args, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BaseDataProviderAccessCoreSystem_UnregisterDataProvider_TisRuntimeObject_mD60FC0708D94C115D8B1A23D3B8E07843F95A4CC_gshared (BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2* __this, RuntimeObject* ___0_dataProviderInstance, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B (RuntimeArray* ___0_array, RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 ___1_fldHandle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem__ctor_m7B2BDFF1519B423EB238B7C6546822A26358BE58 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* ___0_profile, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BaseCoreSystem_set_Registrar_m5E2AD3BA5AD91A736E0A23357E3720E5D94665A8_inline (BaseCoreSystem_t9D02F9BBC05DAD6F987F647B666B37A062ACFAA6* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseDataProviderAccessCoreSystem__ctor_m5F92E54E84428722B0B2712DEDE1E9B019E33719 (BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2* __this, BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* ___0_profile, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_InitializeInternal_mF4B664386C1D9666C03E19BF318BDB859D00BE55 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseService_Initialize_m750DCABB0D54C519B59BADDB050699C41BBC4EFA (BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR MixedRealitySpatialObserverConfigurationU5BU5D_t175B52CA1DE4DF781F77F7FAF9566C4FC8A83884* MixedRealitySpatialAwarenessSystemProfile_get_ObserverConfigurations_m32546F367437EE238C8C9FFF9DF4F104DCD2CA9A_inline (MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* MixedRealitySpatialObserverConfiguration_get_ComponentName_m9E326C6BAA4CEE359983C061C289615CD3A5BA0B_inline (MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t MixedRealitySpatialObserverConfiguration_get_Priority_m51C30C468B10524C42C3598C2E0AD29BCA65DD88_inline (MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BaseSpatialAwarenessObserverProfile_t7A50E95DBFF01391175C2D418C1ABB3C21F43225* MixedRealitySpatialObserverConfiguration_get_ObserverProfile_m04BB069102FDBB62D75BFF4ADC85EDFEA9509466_inline (MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E* MixedRealitySpatialObserverConfiguration_get_ComponentType_m7D5B768E121CE32D1B26CAFB315E734A59CBC14C_inline (MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Type_t* SystemType_get_Type_mBE668A3226CE7032C46D516321F82906389782DA_inline (SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t MixedRealitySpatialObserverConfiguration_get_RuntimePlatform_m32E933F874244B5C0C4C951ABCAB9A90E8174338_inline (MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* __this, const RuntimeMethod* method) ;
inline bool BaseDataProviderAccessCoreSystem_RegisterDataProvider_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_m1BAF0E595E77E9EA59C6B8FCA6D7B86833DB0D68 (BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2* __this, Type_t* ___0_concreteType, String_t* ___1_providerName, int32_t ___2_supportedPlatforms, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___3_args, const RuntimeMethod* method)
{
	return ((  bool (*) (BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2*, Type_t*, String_t*, int32_t, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*, const RuntimeMethod*))BaseDataProviderAccessCoreSystem_RegisterDataProvider_TisRuntimeObject_m754B4E4F42C2591B24170375FC4DD38D68679DF6_gshared)(__this, ___0_concreteType, ___1_providerName, ___2_supportedPlatforms, ___3_args, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseService_Disable_m75AA61136BE79E0C8EA4B058D1506882A56683C4 (BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0* __this, const RuntimeMethod* method) ;
inline bool BaseDataProviderAccessCoreSystem_UnregisterDataProvider_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mCD9464EB917CF367BD8BA93B24804467C4533CF1 (BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2* __this, RuntimeObject* ___0_dataProviderInstance, const RuntimeMethod* method)
{
	return ((  bool (*) (BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2*, RuntimeObject*, const RuntimeMethod*))BaseDataProviderAccessCoreSystem_UnregisterDataProvider_TisRuntimeObject_mD60FC0708D94C115D8B1A23D3B8E07843F95A4CC_gshared)(__this, ___0_dataProviderInstance, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseDataProviderAccessCoreSystem_Enable_m0164D441C4CCECC6D4AFEAF9771CC3CB2D7B2854 (BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseDataProviderAccessCoreSystem_Reset_mCB20FF71C342F6CF354EFFDBA90E01351B1C6693 (BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Application_get_isPlaying_m25B0ABDFEF54F5370CD3F263A813540843D00F34 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Application_get_isEditor_mEAC51E3ACE6DCE438087FB14BD75A3C219D354D0 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_DestroyImmediate_m6336EBC83591A5DB64EC70C92132824C6E258705 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_DetachChildren_m7E4B3405F2F053B059E76EC1DF0F235EED335D69 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseEventSystem_Destroy_m4763A3BA66E9048BD868B9E9632029E94BE9F451 (BaseEventSystem_tB9BD9711D545EEEF00D3162ED9A13EBDE4B1DEA1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* MixedRealitySpatialAwarenessSystem_get_CreateSpatialAwarenessObjectParent_mB6BE3EE9DD033F62073C88450C1BE706758BB6A8 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* MixedRealityPlayspace_get_Transform_mDB12B9D006ADC83AE32D79543E4AAD70CC4EE522 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_SetParent_m9BDD7B7476714B2D7919B10BDC22CE75C0A0A195 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___0_parent, bool ___1_worldPositionStays, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* MixedRealitySpatialAwarenessSystem_get_SpatialAwarenessObjectParent_m0CAE6DD7F708B73C54D0F92DE7D2E0FF1FB0C141 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline (AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AutoScope__ctor_m7F63A273E382CB6328736B6E7F321DDFA40EA9E3_inline (AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139* __this, intptr_t ___0_markerPtr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerUnsafeUtility_EndSample_mFDB4EFB160A9CB817D2F8ED21B88693616B27409 (intptr_t ___0_markerPtr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t ProfilerUnsafeUtility_CreateMarker_mC5E1AAB8CC1F0342065DF85BA3334445ED754E64 (String_t* ___0_name, uint16_t ___1_categoryId, uint16_t ___2_flags, int32_t ___3_metadataCount, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerUnsafeUtility_BeginSample_mB5106F4E7ECEF54906545665ED23928D14F5FCA7 (intptr_t ___0_markerPtr, const RuntimeMethod* method) ;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MonoScriptData_t20F4088CE66646467619047040B266DF5A437888 UnitySourceGeneratedAssemblyMonoScriptTypes_v1_Get_mE48CBCFE348AB11E8BDDFE1A2C331A0B14E968E0 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_t2A6E257BA7214B78EB1995BCD4C6C9FFAE5163C8____0BBB3F47A68A9B10B62A23498D1B4EB5C90D63AFBB2BD20DAAF42DE66F9BA86C_FieldInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_t2A6E257BA7214B78EB1995BCD4C6C9FFAE5163C8____9F273D8B81B87B2FAEF4653458E76AF589A4D75D16BD4B77595C93F0D8FEB888_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	MonoScriptData_t20F4088CE66646467619047040B266DF5A437888 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(MonoScriptData_t20F4088CE66646467619047040B266DF5A437888));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)158));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = L_0;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_2 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_t2A6E257BA7214B78EB1995BCD4C6C9FFAE5163C8____0BBB3F47A68A9B10B62A23498D1B4EB5C90D63AFBB2BD20DAAF42DE66F9BA86C_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_1, L_2, NULL);
		(&V_0)->___FilePathsData = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___FilePathsData), (void*)L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)87));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = L_3;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_5 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_t2A6E257BA7214B78EB1995BCD4C6C9FFAE5163C8____9F273D8B81B87B2FAEF4653458E76AF589A4D75D16BD4B77595C93F0D8FEB888_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_4, L_5, NULL);
		(&V_0)->___TypesData = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___TypesData), (void*)L_4);
		(&V_0)->___TotalFiles = 1;
		(&V_0)->___TotalTypes = 1;
		(&V_0)->___IsEditorOnly = (bool)0;
		MonoScriptData_t20F4088CE66646467619047040B266DF5A437888 L_6 = V_0;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnitySourceGeneratedAssemblyMonoScriptTypes_v1__ctor_mDB925E9C369FF5D84C17420A396E7DFCB4EA445B (UnitySourceGeneratedAssemblyMonoScriptTypes_v1_t6B10F3A424EFE01ACD974D0593A4D0B3AD91B280* __this, const RuntimeMethod* method) 
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
IL2CPP_EXTERN_C void MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshal_pinvoke(const MonoScriptData_t20F4088CE66646467619047040B266DF5A437888& unmarshaled, MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshaled_pinvoke& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshal_pinvoke_back(const MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshaled_pinvoke& marshaled, MonoScriptData_t20F4088CE66646467619047040B266DF5A437888& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	unmarshaled.___FilePathsData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, marshaled.___FilePathsData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___FilePathsData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, marshaled.___FilePathsData));
	unmarshaled.___TypesData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, marshaled.___TypesData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___TypesData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, marshaled.___TypesData));
	int32_t unmarshaledTotalTypes_temp_2 = 0;
	unmarshaledTotalTypes_temp_2 = marshaled.___TotalTypes;
	unmarshaled.___TotalTypes = unmarshaledTotalTypes_temp_2;
	int32_t unmarshaledTotalFiles_temp_3 = 0;
	unmarshaledTotalFiles_temp_3 = marshaled.___TotalFiles;
	unmarshaled.___TotalFiles = unmarshaledTotalFiles_temp_3;
	bool unmarshaledIsEditorOnly_temp_4 = false;
	unmarshaledIsEditorOnly_temp_4 = static_cast<bool>(marshaled.___IsEditorOnly);
	unmarshaled.___IsEditorOnly = unmarshaledIsEditorOnly_temp_4;
}
IL2CPP_EXTERN_C void MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshal_pinvoke_cleanup(MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshaled_pinvoke& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
IL2CPP_EXTERN_C void MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshal_com(const MonoScriptData_t20F4088CE66646467619047040B266DF5A437888& unmarshaled, MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshaled_com& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshal_com_back(const MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshaled_com& marshaled, MonoScriptData_t20F4088CE66646467619047040B266DF5A437888& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	unmarshaled.___FilePathsData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, marshaled.___FilePathsData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___FilePathsData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, marshaled.___FilePathsData));
	unmarshaled.___TypesData = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, marshaled.___TypesData);
	Il2CppCodeGenWriteBarrier((void**)(&unmarshaled.___TypesData), (void*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)il2cpp_codegen_com_marshal_safe_array_result(IL2CPP_VT_I1, Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var, marshaled.___TypesData));
	int32_t unmarshaledTotalTypes_temp_2 = 0;
	unmarshaledTotalTypes_temp_2 = marshaled.___TotalTypes;
	unmarshaled.___TotalTypes = unmarshaledTotalTypes_temp_2;
	int32_t unmarshaledTotalFiles_temp_3 = 0;
	unmarshaledTotalFiles_temp_3 = marshaled.___TotalFiles;
	unmarshaled.___TotalFiles = unmarshaledTotalFiles_temp_3;
	bool unmarshaledIsEditorOnly_temp_4 = false;
	unmarshaledIsEditorOnly_temp_4 = static_cast<bool>(marshaled.___IsEditorOnly);
	unmarshaled.___IsEditorOnly = unmarshaledIsEditorOnly_temp_4;
}
IL2CPP_EXTERN_C void MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshal_com_cleanup(MonoScriptData_t20F4088CE66646467619047040B266DF5A437888_marshaled_com& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem__ctor_m7002337374EA2B974C6033785EF0DA98A259F7AF (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, RuntimeObject* ___0_registrar, MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* ___1_profile, const RuntimeMethod* method) 
{
	{
		MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* L_0 = ___1_profile;
		MixedRealitySpatialAwarenessSystem__ctor_m7B2BDFF1519B423EB238B7C6546822A26358BE58(__this, L_0, NULL);
		RuntimeObject* L_1 = ___0_registrar;
		BaseCoreSystem_set_Registrar_m5E2AD3BA5AD91A736E0A23357E3720E5D94665A8_inline(__this, L_1, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem__ctor_m7B2BDFF1519B423EB238B7C6546822A26358BE58 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* ___0_profile, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral188D30B6EDF85BA42D4E192BE1E93A4D2142FDCB);
		s_Il2CppMethodInitialized = true;
	}
	{
		__this->___U3CNameU3Ek__BackingField = _stringLiteral188D30B6EDF85BA42D4E192BE1E93A4D2142FDCB;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)_stringLiteral188D30B6EDF85BA42D4E192BE1E93A4D2142FDCB);
		MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* L_0 = ___0_profile;
		il2cpp_codegen_runtime_class_init_inline(BaseDataProviderAccessCoreSystem_t30EC4F1C1A10F7586D0EE15069292831A2E3BCF2_il2cpp_TypeInfo_var);
		BaseDataProviderAccessCoreSystem__ctor_m5F92E54E84428722B0B2712DEDE1E9B019E33719(__this, L_0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* MixedRealitySpatialAwarenessSystem_get_Name_m74505A08D759533F20ED9E729624CCCD9DFCF08C (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = __this->___U3CNameU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_set_Name_m525232E4D43A0080D9FE01BE6B6A9F6C0DAAA0AD (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = ___0_value;
		__this->___U3CNameU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CNameU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool MixedRealitySpatialAwarenessSystem_CheckCapability_mD5B285BF58702FE237066F594E07291A00DE0AB7 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, int32_t ___0_capability, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityCapabilityCheck_t89E15A80CA84BBA26759BE2D8A2720CD26534921_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	bool V_2 = false;
	{
		RuntimeObject* L_0;
		L_0 = GenericVirtualFuncInvoker0< RuntimeObject* >::Invoke(MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var, __this);
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var, L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0034:
			{
				{
					RuntimeObject* L_2 = V_0;
					if (!L_2)
					{
						goto IL_003d;
					}
				}
				{
					RuntimeObject* L_3 = V_0;
					NullCheck(L_3);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_3);
				}

IL_003d:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_002a_1;
			}

IL_000e_1:
			{
				RuntimeObject* L_4 = V_0;
				NullCheck(L_4);
				RuntimeObject* L_5;
				L_5 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var, L_4);
				V_1 = ((RuntimeObject*)IsInst((RuntimeObject*)L_5, IMixedRealityCapabilityCheck_t89E15A80CA84BBA26759BE2D8A2720CD26534921_il2cpp_TypeInfo_var));
				RuntimeObject* L_6 = V_1;
				if (!L_6)
				{
					goto IL_002a_1;
				}
			}
			{
				RuntimeObject* L_7 = V_1;
				int32_t L_8 = ___0_capability;
				NullCheck(L_7);
				bool L_9;
				L_9 = InterfaceFuncInvoker1< bool, int32_t >::Invoke(0, IMixedRealityCapabilityCheck_t89E15A80CA84BBA26759BE2D8A2720CD26534921_il2cpp_TypeInfo_var, L_7, L_8);
				if (!L_9)
				{
					goto IL_002a_1;
				}
			}
			{
				V_2 = (bool)1;
				goto IL_0040;
			}

IL_002a_1:
			{
				RuntimeObject* L_10 = V_0;
				NullCheck(L_10);
				bool L_11;
				L_11 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_10);
				if (L_11)
				{
					goto IL_000e_1;
				}
			}
			{
				goto IL_003e;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_003e:
	{
		return (bool)0;
	}

IL_0040:
	{
		bool L_12 = V_2;
		return L_12;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_Initialize_mBB355408A05E67A63E0330EA6BAE4A607B3ADB69 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	{
		VirtualActionInvoker1< bool >::Invoke(32, __this, (bool)0);
		MixedRealitySpatialAwarenessSystem_InitializeInternal_mF4B664386C1D9666C03E19BF318BDB859D00BE55(__this, NULL);
		BaseService_Initialize_m750DCABB0D54C519B59BADDB050699C41BBC4EFA(__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_InitializeInternal_mF4B664386C1D9666C03E19BF318BDB859D00BE55 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseDataProviderAccessCoreSystem_RegisterDataProvider_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_m1BAF0E595E77E9EA59C6B8FCA6D7B86833DB0D68_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IReadOnlyCollection_1_t04A6836A5829DBDAAF26CD938058299A14B25033_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* V_0 = NULL;
	int32_t V_1 = 0;
	MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75 V_2;
	memset((&V_2), 0, sizeof(V_2));
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* V_3 = NULL;
	{
		BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* L_0;
		L_0 = VirtualFuncInvoker0< BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* >::Invoke(22, __this);
		V_0 = ((MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7*)IsInstClass((RuntimeObject*)L_0, MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7_il2cpp_TypeInfo_var));
		MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* L_1 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_2)
		{
			goto IL_0092;
		}
	}
	{
		RuntimeObject* L_3;
		L_3 = GenericVirtualFuncInvoker0< RuntimeObject* >::Invoke(MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var, __this);
		NullCheck(L_3);
		int32_t L_4;
		L_4 = InterfaceFuncInvoker0< int32_t >::Invoke(0, IReadOnlyCollection_1_t04A6836A5829DBDAAF26CD938058299A14B25033_il2cpp_TypeInfo_var, L_3);
		if (L_4)
		{
			goto IL_0092;
		}
	}
	{
		V_1 = 0;
		goto IL_0087;
	}

IL_0026:
	{
		MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* L_5 = V_0;
		NullCheck(L_5);
		MixedRealitySpatialObserverConfigurationU5BU5D_t175B52CA1DE4DF781F77F7FAF9566C4FC8A83884* L_6;
		L_6 = MixedRealitySpatialAwarenessSystemProfile_get_ObserverConfigurations_m32546F367437EE238C8C9FFF9DF4F104DCD2CA9A_inline(L_5, NULL);
		int32_t L_7 = V_1;
		NullCheck(L_6);
		int32_t L_8 = L_7;
		MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75 L_9 = (L_6)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		V_2 = L_9;
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_10 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)SZArrayNew(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var, (uint32_t)4);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_11 = L_10;
		NullCheck(L_11);
		ArrayElementTypeCheck (L_11, __this);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(0), (RuntimeObject*)__this);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_12 = L_11;
		String_t* L_13;
		L_13 = MixedRealitySpatialObserverConfiguration_get_ComponentName_m9E326C6BAA4CEE359983C061C289615CD3A5BA0B_inline((&V_2), NULL);
		NullCheck(L_12);
		ArrayElementTypeCheck (L_12, L_13);
		(L_12)->SetAt(static_cast<il2cpp_array_size_t>(1), (RuntimeObject*)L_13);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_14 = L_12;
		uint32_t L_15;
		L_15 = MixedRealitySpatialObserverConfiguration_get_Priority_m51C30C468B10524C42C3598C2E0AD29BCA65DD88_inline((&V_2), NULL);
		uint32_t L_16 = L_15;
		RuntimeObject* L_17 = Box(UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B_il2cpp_TypeInfo_var, &L_16);
		NullCheck(L_14);
		ArrayElementTypeCheck (L_14, L_17);
		(L_14)->SetAt(static_cast<il2cpp_array_size_t>(2), (RuntimeObject*)L_17);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_18 = L_14;
		BaseSpatialAwarenessObserverProfile_t7A50E95DBFF01391175C2D418C1ABB3C21F43225* L_19;
		L_19 = MixedRealitySpatialObserverConfiguration_get_ObserverProfile_m04BB069102FDBB62D75BFF4ADC85EDFEA9509466_inline((&V_2), NULL);
		NullCheck(L_18);
		ArrayElementTypeCheck (L_18, L_19);
		(L_18)->SetAt(static_cast<il2cpp_array_size_t>(3), (RuntimeObject*)L_19);
		V_3 = L_18;
		SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E* L_20;
		L_20 = MixedRealitySpatialObserverConfiguration_get_ComponentType_m7D5B768E121CE32D1B26CAFB315E734A59CBC14C_inline((&V_2), NULL);
		NullCheck(L_20);
		Type_t* L_21;
		L_21 = SystemType_get_Type_mBE668A3226CE7032C46D516321F82906389782DA_inline(L_20, NULL);
		String_t* L_22;
		L_22 = MixedRealitySpatialObserverConfiguration_get_ComponentName_m9E326C6BAA4CEE359983C061C289615CD3A5BA0B_inline((&V_2), NULL);
		int32_t L_23;
		L_23 = MixedRealitySpatialObserverConfiguration_get_RuntimePlatform_m32E933F874244B5C0C4C951ABCAB9A90E8174338_inline((&V_2), NULL);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_24 = V_3;
		bool L_25;
		L_25 = BaseDataProviderAccessCoreSystem_RegisterDataProvider_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_m1BAF0E595E77E9EA59C6B8FCA6D7B86833DB0D68(__this, L_21, L_22, L_23, L_24, BaseDataProviderAccessCoreSystem_RegisterDataProvider_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_m1BAF0E595E77E9EA59C6B8FCA6D7B86833DB0D68_RuntimeMethod_var);
		int32_t L_26 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_26, 1));
	}

IL_0087:
	{
		int32_t L_27 = V_1;
		MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* L_28 = V_0;
		NullCheck(L_28);
		MixedRealitySpatialObserverConfigurationU5BU5D_t175B52CA1DE4DF781F77F7FAF9566C4FC8A83884* L_29;
		L_29 = MixedRealitySpatialAwarenessSystemProfile_get_ObserverConfigurations_m32546F367437EE238C8C9FFF9DF4F104DCD2CA9A_inline(L_28, NULL);
		NullCheck(L_29);
		if ((((int32_t)L_27) < ((int32_t)((int32_t)(((RuntimeArray*)L_29)->max_length)))))
		{
			goto IL_0026;
		}
	}

IL_0092:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_Disable_m7BB2FBF7420CE0D10B85CF3BA5F99F5232BEB588 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseDataProviderAccessCoreSystem_UnregisterDataProvider_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mCD9464EB917CF367BD8BA93B24804467C4533CF1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* V_0 = NULL;
	RuntimeObject* V_1 = NULL;
	{
		BaseService_Disable_m75AA61136BE79E0C8EA4B058D1506882A56683C4(__this, NULL);
		RuntimeObject* L_0;
		L_0 = GenericVirtualFuncInvoker0< RuntimeObject* >::Invoke(MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var, __this);
		NullCheck(L_0);
		RuntimeObject* L_1;
		L_1 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var, L_0);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_002d:
			{
				{
					RuntimeObject* L_2 = V_0;
					if (!L_2)
					{
						goto IL_0036;
					}
				}
				{
					RuntimeObject* L_3 = V_0;
					NullCheck(L_3);
					InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_3);
				}

IL_0036:
				{
					return;
				}
			}
		});
		try
		{
			{
				goto IL_0023_1;
			}

IL_0014_1:
			{
				RuntimeObject* L_4 = V_0;
				NullCheck(L_4);
				RuntimeObject* L_5;
				L_5 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var, L_4);
				V_1 = L_5;
				RuntimeObject* L_6 = V_1;
				bool L_7;
				L_7 = BaseDataProviderAccessCoreSystem_UnregisterDataProvider_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mCD9464EB917CF367BD8BA93B24804467C4533CF1(__this, L_6, BaseDataProviderAccessCoreSystem_UnregisterDataProvider_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mCD9464EB917CF367BD8BA93B24804467C4533CF1_RuntimeMethod_var);
			}

IL_0023_1:
			{
				RuntimeObject* L_8 = V_0;
				NullCheck(L_8);
				bool L_9;
				L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
				if (L_9)
				{
					goto IL_0014_1;
				}
			}
			{
				goto IL_0037;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0037:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_Enable_mCFD593CC552320ABD6415B1CC61B83738636B3F7 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	{
		MixedRealitySpatialAwarenessSystem_InitializeInternal_mF4B664386C1D9666C03E19BF318BDB859D00BE55(__this, NULL);
		BaseDataProviderAccessCoreSystem_Enable_m0164D441C4CCECC6D4AFEAF9771CC3CB2D7B2854(__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_Reset_m05814D993BEDE5549B232265E18B4E93C844F0A0 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	{
		BaseDataProviderAccessCoreSystem_Reset_mCB20FF71C342F6CF354EFFDBA90E01351B1C6693(__this, NULL);
		VirtualActionInvoker0::Invoke(29, __this);
		VirtualActionInvoker0::Invoke(24, __this);
		VirtualActionInvoker0::Invoke(26, __this);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_Destroy_m0943C993551AB8838CD50161F12D45ED3D32E4B1 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Application_tDB03BE91CDF0ACA614A5E0B67CFB77C44EB19B21_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Application_tDB03BE91CDF0ACA614A5E0B67CFB77C44EB19B21_il2cpp_TypeInfo_var);
		bool L_0;
		L_0 = Application_get_isPlaying_m25B0ABDFEF54F5370CD3F263A813540843D00F34(NULL);
		if (!L_0)
		{
			goto IL_004b;
		}
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1 = __this->___spatialAwarenessObjectParent;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_2)
		{
			goto IL_004b;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Application_tDB03BE91CDF0ACA614A5E0B67CFB77C44EB19B21_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = Application_get_isEditor_mEAC51E3ACE6DCE438087FB14BD75A3C219D354D0(NULL);
		if (!L_3)
		{
			goto IL_0029;
		}
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4 = __this->___spatialAwarenessObjectParent;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_DestroyImmediate_m6336EBC83591A5DB64EC70C92132824C6E258705(L_4, NULL);
		goto IL_0044;
	}

IL_0029:
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5 = __this->___spatialAwarenessObjectParent;
		NullCheck(L_5);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_6;
		L_6 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_5, NULL);
		NullCheck(L_6);
		Transform_DetachChildren_m7E4B3405F2F053B059E76EC1DF0F235EED335D69(L_6, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_7 = __this->___spatialAwarenessObjectParent;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB(L_7, NULL);
	}

IL_0044:
	{
		__this->___spatialAwarenessObjectParent = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___spatialAwarenessObjectParent), (void*)(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL);
	}

IL_004b:
	{
		BaseEventSystem_Destroy_m4763A3BA66E9048BD868B9E9632029E94BE9F451(__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* MixedRealitySpatialAwarenessSystem_get_SpatialAwarenessObjectParent_m0CAE6DD7F708B73C54D0F92DE7D2E0FF1FB0C141 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_0 = NULL;
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___spatialAwarenessObjectParent;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (L_1)
		{
			goto IL_001e;
		}
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
		L_2 = MixedRealitySpatialAwarenessSystem_get_CreateSpatialAwarenessObjectParent_mB6BE3EE9DD033F62073C88450C1BE706758BB6A8(__this, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = L_2;
		V_0 = L_3;
		__this->___spatialAwarenessObjectParent = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___spatialAwarenessObjectParent), (void*)L_3);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4 = V_0;
		return L_4;
	}

IL_001e:
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5 = __this->___spatialAwarenessObjectParent;
		return L_5;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* MixedRealitySpatialAwarenessSystem_get_CreateSpatialAwarenessObjectParent_mB6BE3EE9DD033F62073C88450C1BE706758BB6A8 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral84210E916B771570003864C57344196A52266B35);
		s_Il2CppMethodInitialized = true;
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88(L_0, _stringLiteral84210E916B771570003864C57344196A52266B35, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1 = L_0;
		NullCheck(L_1);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_1, NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_3;
		L_3 = MixedRealityPlayspace_get_Transform_mDB12B9D006ADC83AE32D79543E4AAD70CC4EE522(NULL);
		NullCheck(L_2);
		Transform_SetParent_m9BDD7B7476714B2D7919B10BDC22CE75C0A0A195(L_2, L_3, (bool)0, NULL);
		return L_1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* MixedRealitySpatialAwarenessSystem_CreateSpatialAwarenessObservationParent_m5DE45CF702C4BDFA614F2EBA3FB5D1D7AF4EF30E (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		String_t* L_0 = ___0_name;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88(L_1, L_0, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2 = L_1;
		NullCheck(L_2);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_3;
		L_3 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_2, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4;
		L_4 = MixedRealitySpatialAwarenessSystem_get_SpatialAwarenessObjectParent_m0CAE6DD7F708B73C54D0F92DE7D2E0FF1FB0C141(__this, NULL);
		NullCheck(L_4);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_5;
		L_5 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_4, NULL);
		NullCheck(L_3);
		Transform_SetParent_m9BDD7B7476714B2D7919B10BDC22CE75C0A0A195(L_3, L_5, (bool)0, NULL);
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint32_t MixedRealitySpatialAwarenessSystem_GenerateNewSourceId_m250E35FB9EC4F5B5EFD3F798D29E244C9C06AB6E (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	uint32_t V_0 = 0;
	{
		uint32_t L_0 = __this->___nextSourceId;
		V_0 = L_0;
		uint32_t L_1 = V_0;
		__this->___nextSourceId = ((int32_t)il2cpp_codegen_add((int32_t)L_1, 1));
		uint32_t L_2 = V_0;
		return L_2;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* MixedRealitySpatialAwarenessSystem_get_SpatialAwarenessSystemProfile_mBCBA3CD11AEA0D85056CBE194BDE8DFFE6FB63D6 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* L_0 = __this->___spatialAwarenessSystemProfile;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_001f;
		}
	}
	{
		BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* L_2;
		L_2 = VirtualFuncInvoker0< BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* >::Invoke(22, __this);
		__this->___spatialAwarenessSystemProfile = ((MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7*)IsInstClass((RuntimeObject*)L_2, MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->___spatialAwarenessSystemProfile), (void*)((MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7*)IsInstClass((RuntimeObject*)L_2, MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7_il2cpp_TypeInfo_var)));
	}

IL_001f:
	{
		MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* L_3 = __this->___spatialAwarenessSystemProfile;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MixedRealitySpatialAwarenessSystem_GetObservers_m68AE9837CD79D1BB5A75DA18D90D0624B94AD964 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IReadOnlyList_1_t2B96B7FE2C44634D70F69C777077D230700AD798_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	RuntimeObject* V_2 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___GetObserversPerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_001c:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			RuntimeObject* L_2;
			L_2 = VirtualFuncInvoker0< RuntimeObject* >::Invoke(53, __this);
			V_2 = ((RuntimeObject*)IsInst((RuntimeObject*)L_2, IReadOnlyList_1_t2B96B7FE2C44634D70F69C777077D230700AD798_il2cpp_TypeInfo_var));
			goto IL_002a;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_002a:
	{
		RuntimeObject* L_3 = V_2;
		return L_3;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* MixedRealitySpatialAwarenessSystem_GetObserver_mAE376297629127182D566220D73DA4C428CE53E8 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	RuntimeObject* V_2 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___GetObserverPerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_001d:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			String_t* L_2 = ___0_name;
			RuntimeObject* L_3;
			L_3 = VirtualFuncInvoker1< RuntimeObject*, String_t* >::Invoke(55, __this, L_2);
			V_2 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, IMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_il2cpp_TypeInfo_var));
			goto IL_002b;
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_002b:
	{
		RuntimeObject* L_4 = V_2;
		return L_4;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_ResumeObservers_mB3AD21E9B8211F38FBC5E6ABBFB166CE3C1EDE65 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	RuntimeObject* V_2 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___ResumeObserversPerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_003b:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			{
				RuntimeObject* L_2;
				L_2 = GenericVirtualFuncInvoker0< RuntimeObject* >::Invoke(MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var, __this);
				NullCheck(L_2);
				RuntimeObject* L_3;
				L_3 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var, L_2);
				V_2 = L_3;
			}
			{
				auto __finallyBlock = il2cpp::utils::Finally([&]
				{

FINALLY_0031_1:
					{
						{
							RuntimeObject* L_4 = V_2;
							if (!L_4)
							{
								goto IL_003a_1;
							}
						}
						{
							RuntimeObject* L_5 = V_2;
							NullCheck(L_5);
							InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_5);
						}

IL_003a_1:
						{
							return;
						}
					}
				});
				try
				{
					{
						goto IL_0027_2;
					}

IL_001c_2:
					{
						RuntimeObject* L_6 = V_2;
						NullCheck(L_6);
						RuntimeObject* L_7;
						L_7 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var, L_6);
						NullCheck(L_7);
						InterfaceActionInvoker0::Invoke(16, IMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_il2cpp_TypeInfo_var, L_7);
					}

IL_0027_2:
					{
						RuntimeObject* L_8 = V_2;
						NullCheck(L_8);
						bool L_9;
						L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
						if (L_9)
						{
							goto IL_001c_2;
						}
					}
					{
						goto IL_0049;
					}
				}
				catch(Il2CppExceptionWrapper& e)
				{
					__finallyBlock.StoreException(e.ex);
				}
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0049:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_SuspendObservers_mD9958D09850D1BC3CFFB0CA01BA0D014625A1593 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	RuntimeObject* V_2 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___SuspendObserversPerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_003b:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			{
				RuntimeObject* L_2;
				L_2 = GenericVirtualFuncInvoker0< RuntimeObject* >::Invoke(MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var, __this);
				NullCheck(L_2);
				RuntimeObject* L_3;
				L_3 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var, L_2);
				V_2 = L_3;
			}
			{
				auto __finallyBlock = il2cpp::utils::Finally([&]
				{

FINALLY_0031_1:
					{
						{
							RuntimeObject* L_4 = V_2;
							if (!L_4)
							{
								goto IL_003a_1;
							}
						}
						{
							RuntimeObject* L_5 = V_2;
							NullCheck(L_5);
							InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_5);
						}

IL_003a_1:
						{
							return;
						}
					}
				});
				try
				{
					{
						goto IL_0027_2;
					}

IL_001c_2:
					{
						RuntimeObject* L_6 = V_2;
						NullCheck(L_6);
						RuntimeObject* L_7;
						L_7 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var, L_6);
						NullCheck(L_7);
						InterfaceActionInvoker0::Invoke(17, IMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_il2cpp_TypeInfo_var, L_7);
					}

IL_0027_2:
					{
						RuntimeObject* L_8 = V_2;
						NullCheck(L_8);
						bool L_9;
						L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
						if (L_9)
						{
							goto IL_001c_2;
						}
					}
					{
						goto IL_0049;
					}
				}
				catch(Il2CppExceptionWrapper& e)
				{
					__finallyBlock.StoreException(e.ex);
				}
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0049:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem_ClearObservations_m02B0F31F49F34E05795B81259DEB9F6E785ED2A9 (MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	RuntimeObject* V_2 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___ClearObservationsPerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_003b:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			{
				RuntimeObject* L_2;
				L_2 = GenericVirtualFuncInvoker0< RuntimeObject* >::Invoke(MixedRealitySpatialAwarenessSystem_GetDataProviders_TisIMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_mDC7F0CB34731C65139476D15E4368831ADBFADBC_RuntimeMethod_var, __this);
				NullCheck(L_2);
				RuntimeObject* L_3;
				L_3 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerable_1_tFA9730B1781B4C120870B6E65BFF8A40BCE024A8_il2cpp_TypeInfo_var, L_2);
				V_2 = L_3;
			}
			{
				auto __finallyBlock = il2cpp::utils::Finally([&]
				{

FINALLY_0031_1:
					{
						{
							RuntimeObject* L_4 = V_2;
							if (!L_4)
							{
								goto IL_003a_1;
							}
						}
						{
							RuntimeObject* L_5 = V_2;
							NullCheck(L_5);
							InterfaceActionInvoker0::Invoke(0, IDisposable_t030E0496B4E0E4E4F086825007979AF51F7248C5_il2cpp_TypeInfo_var, L_5);
						}

IL_003a_1:
						{
							return;
						}
					}
				});
				try
				{
					{
						goto IL_0027_2;
					}

IL_001c_2:
					{
						RuntimeObject* L_6 = V_2;
						NullCheck(L_6);
						RuntimeObject* L_7;
						L_7 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(0, IEnumerator_1_t59FDF44DF386D7519C234BF34F19D6732D13AB23_il2cpp_TypeInfo_var, L_6);
						NullCheck(L_7);
						InterfaceActionInvoker0::Invoke(18, IMixedRealitySpatialAwarenessObserver_t6897374ED60E2BA1C5A4ECAF099C486EF526FF15_il2cpp_TypeInfo_var, L_7);
					}

IL_0027_2:
					{
						RuntimeObject* L_8 = V_2;
						NullCheck(L_8);
						bool L_9;
						L_9 = InterfaceFuncInvoker0< bool >::Invoke(0, IEnumerator_t7B609C2FFA6EB5167D9C62A0C32A21DE2F666DAA_il2cpp_TypeInfo_var, L_8);
						if (L_9)
						{
							goto IL_001c_2;
						}
					}
					{
						goto IL_0049;
					}
				}
				catch(Il2CppExceptionWrapper& e)
				{
					__finallyBlock.StoreException(e.ex);
				}
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0049:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealitySpatialAwarenessSystem__cctor_mAFE3197061AE1AD247B96B13A4FCD76B2AAA3C88 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0755F3DCD1C7D7F8C7F146B5C1598C86897222FA);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1493973E273A553C92B106E28BD722E4E3A0AD98);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3AF268028A7C8D24E1A3278EC06A941AF3AB7C83);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral474447FAD0D27BF6A99C1C7093B70018F15EE835);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral56EB1B275FCFAC7E81FE874CCF19B184937C1493);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5C25A67358FA149F467647A046B5549855D72011);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral72F7A6E2A6DE3E5DE76E40BC176AD33FCE86E0A7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral80B8FC02531D63146A2F2DE67A3DC123891215FC);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral91B3ABEA5982C1F945523544B3BA94100AE5F5DB);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB612C75ADB2AE97EA4EA097D17EA7667AA2E78A8);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBEF51D8BFDF5409F7D7A407464E210AB7AF45304);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC4149992C36FE958949693FAE84EE89309D872FA);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC51718E69592BF754ED468BA0E33592D41CC0711);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD7A0E2B84A2188BA28341150550C337C542E8671);
		s_Il2CppMethodInitialized = true;
	}
	{
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0;
		memset((&L_0), 0, sizeof(L_0));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_0), _stringLiteralC51718E69592BF754ED468BA0E33592D41CC0711, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___GetObserversPerfMarker = L_0;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_1;
		memset((&L_1), 0, sizeof(L_1));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_1), _stringLiteral474447FAD0D27BF6A99C1C7093B70018F15EE835, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___GetObserversTPerfMarker = L_1;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_2;
		memset((&L_2), 0, sizeof(L_2));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_2), _stringLiteral0755F3DCD1C7D7F8C7F146B5C1598C86897222FA, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___GetObserverPerfMarker = L_2;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_3;
		memset((&L_3), 0, sizeof(L_3));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_3), _stringLiteral1493973E273A553C92B106E28BD722E4E3A0AD98, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___GetObserverTPerfMarker = L_3;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_4;
		memset((&L_4), 0, sizeof(L_4));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_4), _stringLiteralD7A0E2B84A2188BA28341150550C337C542E8671, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___GetDataProvidersPerfMarker = L_4;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_5;
		memset((&L_5), 0, sizeof(L_5));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_5), _stringLiteral3AF268028A7C8D24E1A3278EC06A941AF3AB7C83, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___GetDataProviderPerfMarker = L_5;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_6;
		memset((&L_6), 0, sizeof(L_6));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_6), _stringLiteral5C25A67358FA149F467647A046B5549855D72011, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___ResumeObserversPerfMarker = L_6;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_7;
		memset((&L_7), 0, sizeof(L_7));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_7), _stringLiteralC4149992C36FE958949693FAE84EE89309D872FA, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___ResumeObserversTPerfMarker = L_7;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_8;
		memset((&L_8), 0, sizeof(L_8));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_8), _stringLiteral72F7A6E2A6DE3E5DE76E40BC176AD33FCE86E0A7, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___ResumeObserverPerfMarker = L_8;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_9;
		memset((&L_9), 0, sizeof(L_9));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_9), _stringLiteralBEF51D8BFDF5409F7D7A407464E210AB7AF45304, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___SuspendObserversPerfMarker = L_9;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_10;
		memset((&L_10), 0, sizeof(L_10));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_10), _stringLiteral91B3ABEA5982C1F945523544B3BA94100AE5F5DB, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___SuspendObserversTPerfMarker = L_10;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_11;
		memset((&L_11), 0, sizeof(L_11));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_11), _stringLiteral80B8FC02531D63146A2F2DE67A3DC123891215FC, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___SuspendObserverPerfMarker = L_11;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_12;
		memset((&L_12), 0, sizeof(L_12));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_12), _stringLiteral56EB1B275FCFAC7E81FE874CCF19B184937C1493, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___ClearObservationsPerfMarker = L_12;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_13;
		memset((&L_13), 0, sizeof(L_13));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_13), _stringLiteralB612C75ADB2AE97EA4EA097D17EA7667AA2E78A8, NULL);
		((MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_StaticFields*)il2cpp_codegen_static_fields_for(MixedRealitySpatialAwarenessSystem_t8D8830FD790974C95CC7531CCA30B7247A13FD90_il2cpp_TypeInfo_var))->___ClearObservationsTPerfMarker = L_13;
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BaseCoreSystem_set_Registrar_m5E2AD3BA5AD91A736E0A23357E3720E5D94665A8_inline (BaseCoreSystem_t9D02F9BBC05DAD6F987F647B666B37A062ACFAA6* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_value;
		__this->___U3CRegistrarU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CRegistrarU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR MixedRealitySpatialObserverConfigurationU5BU5D_t175B52CA1DE4DF781F77F7FAF9566C4FC8A83884* MixedRealitySpatialAwarenessSystemProfile_get_ObserverConfigurations_m32546F367437EE238C8C9FFF9DF4F104DCD2CA9A_inline (MixedRealitySpatialAwarenessSystemProfile_t84A6651AAFB01D051CB46EFFB648247FA23035D7* __this, const RuntimeMethod* method) 
{
	{
		MixedRealitySpatialObserverConfigurationU5BU5D_t175B52CA1DE4DF781F77F7FAF9566C4FC8A83884* L_0 = __this->___observerConfigurations;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* MixedRealitySpatialObserverConfiguration_get_ComponentName_m9E326C6BAA4CEE359983C061C289615CD3A5BA0B_inline (MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* __this, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = __this->___componentName;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint32_t MixedRealitySpatialObserverConfiguration_get_Priority_m51C30C468B10524C42C3598C2E0AD29BCA65DD88_inline (MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* __this, const RuntimeMethod* method) 
{
	{
		uint32_t L_0 = __this->___priority;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR BaseSpatialAwarenessObserverProfile_t7A50E95DBFF01391175C2D418C1ABB3C21F43225* MixedRealitySpatialObserverConfiguration_get_ObserverProfile_m04BB069102FDBB62D75BFF4ADC85EDFEA9509466_inline (MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* __this, const RuntimeMethod* method) 
{
	{
		BaseSpatialAwarenessObserverProfile_t7A50E95DBFF01391175C2D418C1ABB3C21F43225* L_0 = __this->___observerProfile;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E* MixedRealitySpatialObserverConfiguration_get_ComponentType_m7D5B768E121CE32D1B26CAFB315E734A59CBC14C_inline (MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* __this, const RuntimeMethod* method) 
{
	{
		SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E* L_0 = __this->___componentType;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Type_t* SystemType_get_Type_mBE668A3226CE7032C46D516321F82906389782DA_inline (SystemType_t9C9A555B60497C18297AD1082247C2960A7B666E* __this, const RuntimeMethod* method) 
{
	{
		Type_t* L_0 = __this->___type;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t MixedRealitySpatialObserverConfiguration_get_RuntimePlatform_m32E933F874244B5C0C4C951ABCAB9A90E8174338_inline (MixedRealitySpatialObserverConfiguration_tD6661687B3B62C35D39F64D13472802F6624DB75* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___runtimePlatform;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, const RuntimeMethod* method) 
{
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		intptr_t L_0 = __this->___m_Ptr;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		memset((&L_1), 0, sizeof(L_1));
		AutoScope__ctor_m7F63A273E382CB6328736B6E7F321DDFA40EA9E3_inline((&L_1), L_0, NULL);
		V_0 = L_1;
		goto IL_000f;
	}

IL_000f:
	{
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_2 = V_0;
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline (AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		intptr_t L_0 = __this->___m_Ptr;
		bool L_1;
		L_1 = IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B(L_0, 0, NULL);
		V_0 = L_1;
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_0021;
		}
	}
	{
		intptr_t L_3 = __this->___m_Ptr;
		ProfilerUnsafeUtility_EndSample_mFDB4EFB160A9CB817D2F8ED21B88693616B27409(L_3, NULL);
	}

IL_0021:
	{
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, String_t* ___0_name, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = ___0_name;
		intptr_t L_1;
		L_1 = ProfilerUnsafeUtility_CreateMarker_mC5E1AAB8CC1F0342065DF85BA3334445ED754E64(L_0, (uint16_t)1, 0, 0, NULL);
		__this->___m_Ptr = L_1;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AutoScope__ctor_m7F63A273E382CB6328736B6E7F321DDFA40EA9E3_inline (AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139* __this, intptr_t ___0_markerPtr, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		intptr_t L_0 = ___0_markerPtr;
		__this->___m_Ptr = L_0;
		intptr_t L_1 = __this->___m_Ptr;
		bool L_2;
		L_2 = IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B(L_1, 0, NULL);
		V_0 = L_2;
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_0023;
		}
	}
	{
		intptr_t L_4 = ___0_markerPtr;
		ProfilerUnsafeUtility_BeginSample_mB5106F4E7ECEF54906545665ED23928D14F5FCA7(L_4, NULL);
	}

IL_0023:
	{
		return;
	}
}
