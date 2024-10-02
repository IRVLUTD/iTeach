#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


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

struct Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340;
struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87;
struct List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E;
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E;
struct JointKinematicBodyU5BU5D_t1FCA6A6F3261FF5CF58A162C3A688F120E5B7A6E;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915;
struct BaseExtensionService_tAAAB770DE97BB6A278B30D7C7F0E2E39CA8108C4;
struct BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4;
struct BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0;
struct CancellationTokenSource_tAAE1E0033BCFC233801F8CB4CED5C852B350CB7B;
struct Collider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76;
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2;
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
struct HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890;
struct HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD;
struct IMixedRealityHandJointService_t335A41FECB2854EF54AEF3B6ABD1CAE631731895;
struct IMixedRealityServiceRegistrar_t4B893B7CDAAC977211D826D02C8522ECA327D715;
struct JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E;
struct MethodInfo_t;
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
struct Rigidbody_t268697F5A994213ED97393309870968BC1C7393C;
struct String_t;
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1;
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_tB7D0872E1C1AD6B7CC732A54B674F3E978100BCE;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;

IL2CPP_EXTERN_C RuntimeClass* ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Byte_t94D9231AC217BE4D2E004C4CD32DF6D099EA41A3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CoreServices_tCB1FB80E338B89BCA07C52C15B876BC6D4B3439B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Handedness_t8F3D346D04DED9C8F19FDD0EAB3DFFF385E485FF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMixedRealityHandJointService_t335A41FECB2854EF54AEF3B6ABD1CAE631731895_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TrackedHandJoint_tEDCBD4B9A65BBB59D6C182873CEF88E1A12A356B_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99____07AB8B46B28C471E28A0B0877DC27A855CE78CC184C10408FBAAD5A0F06FDD81_FieldInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99____1D60BFA4DA6189B83EBBC11697FFD2677EC607C7DD8268DBA37D6E50A600836F_FieldInfo_var;
IL2CPP_EXTERN_C RuntimeField* U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99____3F88FBB7FD9DDD81E9E2A619815356D8409B35AEFD4F2B0F9CD9473E251D468B_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral1B7C657456EEB67D39103E7D53301AB040007E6F;
IL2CPP_EXTERN_C String_t* _stringLiteral1C7FAA54D286D9BC344C94963A928369C13F9604;
IL2CPP_EXTERN_C String_t* _stringLiteral1D091D04287D4679285A2E663193C6F6B9AFDEAA;
IL2CPP_EXTERN_C String_t* _stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745;
IL2CPP_EXTERN_C String_t* _stringLiteral2CA525E745821399EEF6F1D2733A285A82160939;
IL2CPP_EXTERN_C String_t* _stringLiteralC1738C3F31C42EB3867F885AD91436A640396392;
IL2CPP_EXTERN_C String_t* _stringLiteralDA498934C25635BF965454E7B0EFC76A87F36A1B;
IL2CPP_EXTERN_C String_t* _stringLiteralE32213B913E2692579F46DFC5F32A1E135F596B6;
IL2CPP_EXTERN_C const RuntimeMethod* CoreServices_GetInputSystemDataProvider_TisIMixedRealityHandJointService_t335A41FECB2854EF54AEF3B6ABD1CAE631731895_m13D533E8D99B503A46A41E24A57938F8EAF84790_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_m8A20A8D117EA8E863E484FCBF3E5DF8B4F2DF6FE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_mF5408289067372E7D77623ADFE1E7741F1ADADEA_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_mD3D72C58C7DBD2C1244CACC126D52940E0ADAE57_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_GetComponent_TisCollider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76_m4CB0FC4E59CE6C91F1106739EF364208A63E2597_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_GetComponent_TisJointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_mDC52B1A4AFD97A35D7CC54CE006568DC2F65A3D5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_GetComponent_TisRigidbody_t268697F5A994213ED97393309870968BC1C7393C_m2D7F86C77ECF9B82AAC077B511F1004280571B90_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m24FC1392D880374B2CB030D8742BDB1546E86FF3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_GetEnumerator_m70A301919477330858A06AE312F1ED809CCB9E72_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m6F3F17D02E1F01C3386C4C3FDFB56ADD80D1A192_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_m0AD894688377C5604795014FBCA9A265B896B417_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m58C654F1134533E29502629CA67645682B404811_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;

struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
struct HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct U3CModuleU3E_t4BB608EBE04FE4CF2667A6ED7D8303083D1D95F5 
{
};
struct List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E  : public RuntimeObject
{
	JointKinematicBodyU5BU5D_t1FCA6A6F3261FF5CF58A162C3A688F120E5B7A6E* ____items;
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
struct U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct UnitySourceGeneratedAssemblyMonoScriptTypes_v1_tB7D0872E1C1AD6B7CC732A54B674F3E978100BCE  : public RuntimeObject
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
struct Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39 
{
	List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* ____list;
	int32_t ____index;
	int32_t ____version;
	JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* ____current;
};
struct Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A 
{
	List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* ____list;
	int32_t ____index;
	int32_t ____version;
	RuntimeObject* ____current;
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
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
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
struct __StaticArrayInitTypeSizeU3D20_t31F020E039F15B5E5F46A6A82343E4A187CF74C8 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D20_t31F020E039F15B5E5F46A6A82343E4A187CF74C8__padding[20];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D316_t78990AF3C7F6C60135F1172BF8ABC831EDDFC46D 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D316_t78990AF3C7F6C60135F1172BF8ABC831EDDFC46D__padding[316];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D535_t05431F647CAE9A025AFA72D19A7A932554879F73 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D535_t05431F647CAE9A025AFA72D19A7A932554879F73__padding[535];
	};
};
#pragma pack(pop, tp)
struct MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC 
{
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___FilePathsData;
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	bool ___IsEditorOnly;
};
struct MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshaled_pinvoke
{
	Il2CppSafeArray* ___FilePathsData;
	Il2CppSafeArray* ___TypesData;
	int32_t ___TotalTypes;
	int32_t ___TotalFiles;
	int32_t ___IsEditorOnly;
};
struct MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshaled_com
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
struct Handedness_t8F3D346D04DED9C8F19FDD0EAB3DFFF385E485FF 
{
	uint8_t ___value__;
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
struct TrackedHandJoint_tEDCBD4B9A65BBB59D6C182873CEF88E1A12A356B 
{
	int32_t ___value__;
};
struct AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 
{
	intptr_t ___m_Ptr;
};
struct BaseExtensionService_tAAAB770DE97BB6A278B30D7C7F0E2E39CA8108C4  : public BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0
{
	RuntimeObject* ___U3CRegistrarU3Ek__BackingField;
};
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
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
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_pinvoke : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
};
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_com : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
};
struct Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340  : public MulticastDelegate_t
{
};
struct Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87  : public MulticastDelegate_t
{
};
struct BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	bool ___isCustomProfile;
};
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};
struct Collider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};
struct HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890  : public BaseExtensionService_tAAAB770DE97BB6A278B30D7C7F0E2E39CA8108C4
{
	HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* ___handPhysicsServiceProfile;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___U3CHandPhysicsServiceRootU3Ek__BackingField;
	int32_t ___U3CHandPhysicsLayerU3Ek__BackingField;
	bool ___U3CUsePalmKinematicBodyU3Ek__BackingField;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___fingerTipKinematicBodyPrefab;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___palmKinematicBodyPrefab;
	RuntimeObject* ___handJointService;
	List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* ___jointKinematicBodies;
};
struct Rigidbody_t268697F5A994213ED97393309870968BC1C7393C  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};
struct HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD  : public BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4
{
	int32_t ___handPhysicsLayer;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___fingerTipKinematicBodyPrefab;
	bool ___usePalmKinematicBody;
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___palmKinematicBodyPrefab;
};
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
	CancellationTokenSource_tAAE1E0033BCFC233801F8CB4CED5C852B350CB7B* ___m_CancellationTokenSource;
};
struct JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___U3CJointU3Ek__BackingField;
	uint8_t ___U3CHandednessTypeU3Ek__BackingField;
	int32_t ___U3CJointTypeU3Ek__BackingField;
	Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* ___U3COnEnableActionU3Ek__BackingField;
	Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* ___U3COnDisableActionU3Ek__BackingField;
};
struct List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E_StaticFields
{
	JointKinematicBodyU5BU5D_t1FCA6A6F3261FF5CF58A162C3A688F120E5B7A6E* ___s_emptyArray;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray;
};
struct U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99_StaticFields
{
	__StaticArrayInitTypeSizeU3D535_t05431F647CAE9A025AFA72D19A7A932554879F73 ___07AB8B46B28C471E28A0B0877DC27A855CE78CC184C10408FBAAD5A0F06FDD81;
	__StaticArrayInitTypeSizeU3D316_t78990AF3C7F6C60135F1172BF8ABC831EDDFC46D ___1D60BFA4DA6189B83EBBC11697FFD2677EC607C7DD8268DBA37D6E50A600836F;
	__StaticArrayInitTypeSizeU3D20_t31F020E039F15B5E5F46A6A82343E4A187CF74C8 ___3F88FBB7FD9DDD81E9E2A619815356D8409B35AEFD4F2B0F9CD9473E251D468B;
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
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_StaticFields
{
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___enumSeperatorCharArray;
};
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974_StaticFields
{
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___identityQuaternion;
};
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___zeroVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___oneVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___downVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___leftVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___rightVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___forwardVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___backVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___positiveInfinityVector;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___negativeInfinityVector;
};
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject;
};
struct HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields
{
	HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E* ___handednessTypes;
	TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915* ___fingerTipTypes;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdatePerfMarker;
};
struct JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_StaticFields
{
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdateStatePerfMarker;
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
struct HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E  : public RuntimeArray
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
struct TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915  : public RuntimeArray
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


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* CoreServices_GetInputSystemDataProvider_TisRuntimeObject_mD8D3FD5E4D793C8959090BE7F44C7A78C02CABD0_gshared (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Object_Instantiate_TisRuntimeObject_m75BF3B0A3747B60491845FA41612FE7F795F0A59_gshared (RuntimeObject* ___0_original, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___1_parent, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_mF2422B2DD29F74CE66F791C3F68E288EC7C3DB9E_gshared_inline (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B (RuntimeArray* ___0_array, RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 ___1_fldHandle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
inline void List_1__ctor_m6F3F17D02E1F01C3386C4C3FDFB56ADD80D1A192 (List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseExtensionService__ctor_m749767F57B9F1E914EA6AFF4943A36CFF7CC257E (BaseExtensionService_tAAAB770DE97BB6A278B30D7C7F0E2E39CA8108C4* __this, String_t* ___0_name, uint32_t ___1_priority, BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* ___2_profile, const RuntimeMethod* method) ;
inline RuntimeObject* CoreServices_GetInputSystemDataProvider_TisIMixedRealityHandJointService_t335A41FECB2854EF54AEF3B6ABD1CAE631731895_m13D533E8D99B503A46A41E24A57938F8EAF84790 (const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (const RuntimeMethod*))CoreServices_GetInputSystemDataProvider_TisRuntimeObject_mD8D3FD5E4D793C8959090BE7F44C7A78C02CABD0_gshared)(method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_CreateKinematicBodies_mE673FFE4CDCFAB6546CB9DBFE3259D2E46B182A2 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_DestroyKinematicBodies_mDB3070DCFE31CED79AAD71EFC0A35CD531812C5E (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseService_Initialize_m750DCABB0D54C519B59BADDB050699C41BBC4EFA (BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HandPhysicsServiceProfile_get_HandPhysicsLayer_m9E5EBC77EC9B960FB18B65D94BF42F7EA8CA50C6_inline (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void HandPhysicsService_set_HandPhysicsLayer_m7BF4CB7E70EFB6CD80F3F77CBAE771716FF79ED0_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool HandPhysicsServiceProfile_get_UsePalmKinematicBody_m81F8E9FFACFE8A9C4140EFFFA03D47E40AAC3D9A_inline (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void HandPhysicsService_set_UsePalmKinematicBody_m67BE8E1211A0B1B165E25B82D3F879D409450694_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsServiceProfile_get_FingerTipKinematicBodyPrefab_m642AA6044A1D1F2E0BD7F19E840EC3201987A8AB_inline (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_set_FingerTipKinematicBodyPrefab_m985C16BC725F354142C6B4E254C76476038FABE7 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsServiceProfile_get_PalmKinematicBodyPrefab_mE62F22D0A4E4DFE47FBF60A5C354D1150E90AF21_inline (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_set_PalmKinematicBodyPrefab_mFE5C9BCCEACC998D31A8058EA4FC240FA324B6DB (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseService_Enable_mF054160CA265761A1223A3F8CFE50A976C7297E8 (BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void HandPhysicsService_set_HandPhysicsServiceRoot_m99C4CB7F02C191EB88579EA58D138D144030A892_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsService_get_HandPhysicsServiceRoot_mEDA47B73985CFE5593713DA7268AAB07C0321934_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_obj, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseService_Disable_m75AA61136BE79E0C8EA4B058D1506882A56683C4 (BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline (AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseService_Update_m07A22E1552ABDCD9AD86737D12D43DA27915370D (BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0* __this, const RuntimeMethod* method) ;
inline Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39 List_1_GetEnumerator_m70A301919477330858A06AE312F1ED809CCB9E72 (List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39 (*) (List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E*, const RuntimeMethod*))List_1_GetEnumerator_mD8294A7FA2BEB1929487127D476F8EC1CDC23BFC_gshared)(__this, method);
}
inline void Enumerator_Dispose_m8A20A8D117EA8E863E484FCBF3E5DF8B4F2DF6FE (Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39*, const RuntimeMethod*))Enumerator_Dispose_mD9DC3E3C3697830A4823047AB29A77DBBB5ED419_gshared)(__this, method);
}
inline JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* Enumerator_get_Current_mD3D72C58C7DBD2C1244CACC126D52940E0ADAE57_inline (Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39* __this, const RuntimeMethod* method)
{
	return ((  JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* (*) (Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39*, const RuntimeMethod*))Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HandPhysicsService_get_HandJointService_m69A7B84777D87F1E98C9557BAE7A446F6EF5C3AE (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t JointKinematicBody_get_HandednessType_m77B12ADB2D2CD12BD3B0F4B6B88741489939CC9E_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* JointKinematicBody_get_Joint_m7CD5366B9380ACAD28E0C3D9911375F99B40B3DD_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t JointKinematicBody_get_JointType_m73DC834B823F8BE1147C1C911B5572E9D2A45B33_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void JointKinematicBody_set_Joint_m9AA4BFBBC07572113292EC77A012F144B569164A_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void JointKinematicBody_UpdateState_m3B4BF726E3531FD7A1FE46D8E4C80CFA81B9C6EA (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, bool ___0_active, const RuntimeMethod* method) ;
inline bool Enumerator_MoveNext_mF5408289067372E7D77623ADFE1E7741F1ADADEA (Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39*, const RuntimeMethod*))Enumerator_MoveNext_mE921CC8F29FBBDE7CC3209A0ED0D921D58D00BCB_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsService_get_FingerTipKinematicBodyPrefab_mDCEB71782ABC9AB74ED4E97F4066F3D535667A4D_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HandPhysicsService_get_HandPhysicsLayer_m0F8368510837B9E4B871D09A7A6DAEB09FB4D4E4_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HandPhysicsService_TryCreateJointKinematicBody_m4B9D0F1B46E1BC215BA1B5436302641C747B9E66 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_rigidBodyPrefab, int32_t ___1_layer, uint8_t ___2_handednessType, int32_t ___3_jointType, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___4_parent, JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E** ___5_jointKinematicBody, const RuntimeMethod* method) ;
inline void List_1_Add_m24FC1392D880374B2CB030D8742BDB1546E86FF3_inline (List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* __this, JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E*, JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool HandPhysicsService_get_UsePalmKinematicBody_mBB0C082F0A6D6CB2603F308881440016BEC4083A_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsService_get_PalmKinematicBodyPrefab_m8F15CD10E8BE3A1F0BEE38027CFB41F265F8BE5F_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) ;
inline int32_t List_1_get_Count_m0AD894688377C5604795014FBCA9A265B896B417_inline (List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E*, const RuntimeMethod*))List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
inline GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m58C654F1134533E29502629CA67645682B404811 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_original, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___1_parent, const RuntimeMethod* method)
{
	return ((  GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1*, const RuntimeMethod*))Object_Instantiate_TisRuntimeObject_m75BF3B0A3747B60491845FA41612FE7F795F0A59_gshared)(___0_original, ___1_parent, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject_set_layer_m6E1AF478A2CC86BD222B96317BEB78B7D89B18D0 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, int32_t ___0_value, const RuntimeMethod* method) ;
inline JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* GameObject_GetComponent_TisJointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_mDC52B1A4AFD97A35D7CC54CE006568DC2F65A3D5 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void JointKinematicBody_set_JointType_m7C023561616D22CFEEA796AB2D9334BDA6A0FAD0_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void JointKinematicBody_set_HandednessType_m894E251DC1625B3DAF1478896419E4551C5E6E5B_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, uint8_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741 (RuntimeObject* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_set_name_mC79E6DC8FFD72479C90F0C4CC7F42A0FEAF5AE47 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* __this, String_t* ___0_value, const RuntimeMethod* method) ;
inline Collider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76* GameObject_GetComponent_TisCollider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76_m4CB0FC4E59CE6C91F1106739EF364208A63E2597 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  Collider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared)(__this, method);
}
inline Rigidbody_t268697F5A994213ED97393309870968BC1C7393C* GameObject_GetComponent_TisRigidbody_t268697F5A994213ED97393309870968BC1C7393C_m2D7F86C77ECF9B82AAC077B511F1004280571B90 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  Rigidbody_t268697F5A994213ED97393309870968BC1C7393C* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_GetComponent_TisRuntimeObject_m6EAED4AA356F0F48288F67899E5958792395563B_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Rigidbody_get_isKinematic_mC20906CA5A89983DE06EAC6E3AFC5BC012F90CA1 (Rigidbody_t268697F5A994213ED97393309870968BC1C7393C* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Rigidbody_set_isKinematic_m6C3FD3EA358DADA3B191F2449CF1C4F8B22695ED (Rigidbody_t268697F5A994213ED97393309870968BC1C7393C* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseMixedRealityProfile__ctor_mE6D5359B74BAAEA74B1F24297F435C969CD43DFE (BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool GameObject_get_activeSelf_m4F3E5240E138B66AAA080EA30759A3D0517DA368 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_set_rotation_m61340DE74726CF0F9946743A727C4D444397331D (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* JointKinematicBody_get_OnEnableAction_m3F01CA478D48E1BF10E3F82617AFE23694C3EB96_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) ;
inline void Action_1_Invoke_m04C0747C16026AF8A583ADA4927B57C5426E544F_inline (Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* __this, JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* ___0_obj, const RuntimeMethod* method)
{
	((  void (*) (Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340*, JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E*, const RuntimeMethod*))Action_1_Invoke_mF2422B2DD29F74CE66F791C3F68E288EC7C3DB9E_gshared_inline)(__this, ___0_obj, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* JointKinematicBody_get_OnDisableAction_m5B477E4517FBEA9D2518C9F7823EE43C8C511223_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AutoScope__ctor_m7F63A273E382CB6328736B6E7F321DDFA40EA9E3_inline (AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139* __this, intptr_t ___0_markerPtr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerUnsafeUtility_EndSample_mFDB4EFB160A9CB817D2F8ED21B88693616B27409 (intptr_t ___0_markerPtr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t ProfilerUnsafeUtility_CreateMarker_mC5E1AAB8CC1F0342065DF85BA3334445ED754E64 (String_t* ___0_name, uint16_t ___1_categoryId, uint16_t ___2_flags, int32_t ___3_metadataCount, const RuntimeMethod* method) ;
inline void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4 (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D*, RuntimeObject*, const RuntimeMethod*))List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared)(__this, ___0_item, method);
}
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC UnitySourceGeneratedAssemblyMonoScriptTypes_v1_Get_mC3007D27B3276D092BBCE0005968EE469DA0D0D8 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99____07AB8B46B28C471E28A0B0877DC27A855CE78CC184C10408FBAAD5A0F06FDD81_FieldInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99____1D60BFA4DA6189B83EBBC11697FFD2677EC607C7DD8268DBA37D6E50A600836F_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		il2cpp_codegen_initobj((&V_0), sizeof(MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_0 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)535));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_1 = L_0;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_2 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99____07AB8B46B28C471E28A0B0877DC27A855CE78CC184C10408FBAAD5A0F06FDD81_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_1, L_2, NULL);
		(&V_0)->___FilePathsData = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___FilePathsData), (void*)L_1);
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_3 = (ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031*)SZArrayNew(ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031_il2cpp_TypeInfo_var, (uint32_t)((int32_t)316));
		ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* L_4 = L_3;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_5 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99____1D60BFA4DA6189B83EBBC11697FFD2677EC607C7DD8268DBA37D6E50A600836F_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_4, L_5, NULL);
		(&V_0)->___TypesData = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&(&V_0)->___TypesData), (void*)L_4);
		(&V_0)->___TotalFiles = 4;
		(&V_0)->___TotalTypes = 4;
		(&V_0)->___IsEditorOnly = (bool)0;
		MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC L_6 = V_0;
		return L_6;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnitySourceGeneratedAssemblyMonoScriptTypes_v1__ctor_mEDB11AF832ABA39602F4932DF135D511250AC082 (UnitySourceGeneratedAssemblyMonoScriptTypes_v1_tB7D0872E1C1AD6B7CC732A54B674F3E978100BCE* __this, const RuntimeMethod* method) 
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
IL2CPP_EXTERN_C void MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshal_pinvoke(const MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC& unmarshaled, MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshaled_pinvoke& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshal_pinvoke_back(const MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshaled_pinvoke& marshaled, MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC& unmarshaled)
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
IL2CPP_EXTERN_C void MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshal_pinvoke_cleanup(MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshaled_pinvoke& marshaled)
{
	il2cpp_codegen_com_destroy_safe_array(marshaled.___FilePathsData);
	marshaled.___FilePathsData = NULL;
	il2cpp_codegen_com_destroy_safe_array(marshaled.___TypesData);
	marshaled.___TypesData = NULL;
}
IL2CPP_EXTERN_C void MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshal_com(const MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC& unmarshaled, MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshaled_com& marshaled)
{
	marshaled.___FilePathsData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___FilePathsData);
	marshaled.___TypesData = il2cpp_codegen_com_marshal_safe_array(IL2CPP_VT_I1, unmarshaled.___TypesData);
	marshaled.___TotalTypes = unmarshaled.___TotalTypes;
	marshaled.___TotalFiles = unmarshaled.___TotalFiles;
	marshaled.___IsEditorOnly = static_cast<int32_t>(unmarshaled.___IsEditorOnly);
}
IL2CPP_EXTERN_C void MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshal_com_back(const MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshaled_com& marshaled, MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC& unmarshaled)
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
IL2CPP_EXTERN_C void MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshal_com_cleanup(MonoScriptData_t4ADE6FBF16EA802D4588E1446DD3ECBE3998C9FC_marshaled_com& marshaled)
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService__ctor_m008C02E306167903086AE12A0E3B6AA18D01B291 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, String_t* ___0_name, uint32_t ___1_priority, BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* ___2_profile, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m6F3F17D02E1F01C3386C4C3FDFB56ADD80D1A192_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* L_0 = (List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E*)il2cpp_codegen_object_new(List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E_il2cpp_TypeInfo_var);
		List_1__ctor_m6F3F17D02E1F01C3386C4C3FDFB56ADD80D1A192(L_0, List_1__ctor_m6F3F17D02E1F01C3386C4C3FDFB56ADD80D1A192_RuntimeMethod_var);
		__this->___jointKinematicBodies = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___jointKinematicBodies), (void*)L_0);
		String_t* L_1 = ___0_name;
		uint32_t L_2 = ___1_priority;
		BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* L_3 = ___2_profile;
		BaseExtensionService__ctor_m749767F57B9F1E914EA6AFF4943A36CFF7CC257E(__this, L_1, L_2, L_3, NULL);
		BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* L_4 = ___2_profile;
		__this->___handPhysicsServiceProfile = ((HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD*)CastclassClass((RuntimeObject*)L_4, HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->___handPhysicsServiceProfile), (void*)((HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD*)CastclassClass((RuntimeObject*)L_4, HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD_il2cpp_TypeInfo_var)));
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* HandPhysicsService_get_HandJointService_m69A7B84777D87F1E98C9557BAE7A446F6EF5C3AE (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreServices_GetInputSystemDataProvider_TisIMixedRealityHandJointService_t335A41FECB2854EF54AEF3B6ABD1CAE631731895_m13D533E8D99B503A46A41E24A57938F8EAF84790_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CoreServices_tCB1FB80E338B89BCA07C52C15B876BC6D4B3439B_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	RuntimeObject* G_B2_0 = NULL;
	RuntimeObject* G_B1_0 = NULL;
	{
		RuntimeObject* L_0 = __this->___handJointService;
		RuntimeObject* L_1 = L_0;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000f;
		}
		G_B1_0 = L_1;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(CoreServices_tCB1FB80E338B89BCA07C52C15B876BC6D4B3439B_il2cpp_TypeInfo_var);
		RuntimeObject* L_2;
		L_2 = CoreServices_GetInputSystemDataProvider_TisIMixedRealityHandJointService_t335A41FECB2854EF54AEF3B6ABD1CAE631731895_m13D533E8D99B503A46A41E24A57938F8EAF84790(CoreServices_GetInputSystemDataProvider_TisIMixedRealityHandJointService_t335A41FECB2854EF54AEF3B6ABD1CAE631731895_m13D533E8D99B503A46A41E24A57938F8EAF84790_RuntimeMethod_var);
		G_B2_0 = L_2;
	}

IL_000f:
	{
		return G_B2_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsService_get_HandPhysicsServiceRoot_mEDA47B73985CFE5593713DA7268AAB07C0321934 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___U3CHandPhysicsServiceRootU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_set_HandPhysicsServiceRoot_m99C4CB7F02C191EB88579EA58D138D144030A892 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_value;
		__this->___U3CHandPhysicsServiceRootU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CHandPhysicsServiceRootU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HandPhysicsService_get_HandPhysicsLayer_m0F8368510837B9E4B871D09A7A6DAEB09FB4D4E4 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CHandPhysicsLayerU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_set_HandPhysicsLayer_m7BF4CB7E70EFB6CD80F3F77CBAE771716FF79ED0 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->___U3CHandPhysicsLayerU3Ek__BackingField = L_0;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HandPhysicsService_get_UsePalmKinematicBody_mBB0C082F0A6D6CB2603F308881440016BEC4083A (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___U3CUsePalmKinematicBodyU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_set_UsePalmKinematicBody_m67BE8E1211A0B1B165E25B82D3F879D409450694 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		bool L_0 = ___0_value;
		__this->___U3CUsePalmKinematicBodyU3Ek__BackingField = L_0;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsService_get_FingerTipKinematicBodyPrefab_mDCEB71782ABC9AB74ED4E97F4066F3D535667A4D (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___fingerTipKinematicBodyPrefab;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_set_FingerTipKinematicBodyPrefab_m985C16BC725F354142C6B4E254C76476038FABE7 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_value;
		__this->___fingerTipKinematicBodyPrefab = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___fingerTipKinematicBodyPrefab), (void*)L_0);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1 = __this->___fingerTipKinematicBodyPrefab;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_2)
		{
			goto IL_001c;
		}
	}
	{
		HandPhysicsService_CreateKinematicBodies_mE673FFE4CDCFAB6546CB9DBFE3259D2E46B182A2(__this, NULL);
		return;
	}

IL_001c:
	{
		HandPhysicsService_DestroyKinematicBodies_mDB3070DCFE31CED79AAD71EFC0A35CD531812C5E(__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsService_get_PalmKinematicBodyPrefab_m8F15CD10E8BE3A1F0BEE38027CFB41F265F8BE5F (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___palmKinematicBodyPrefab;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_set_PalmKinematicBodyPrefab_mFE5C9BCCEACC998D31A8058EA4FC240FA324B6DB (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_value;
		__this->___palmKinematicBodyPrefab = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___palmKinematicBodyPrefab), (void*)L_0);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1 = __this->___palmKinematicBodyPrefab;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_2)
		{
			goto IL_001c;
		}
	}
	{
		HandPhysicsService_CreateKinematicBodies_mE673FFE4CDCFAB6546CB9DBFE3259D2E46B182A2(__this, NULL);
		return;
	}

IL_001c:
	{
		HandPhysicsService_DestroyKinematicBodies_mDB3070DCFE31CED79AAD71EFC0A35CD531812C5E(__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_Initialize_mA53E4A016752B6433FD2FD62C67B9F1E1C63882A (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		BaseService_Initialize_m750DCABB0D54C519B59BADDB050699C41BBC4EFA(__this, NULL);
		HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* L_0 = __this->___handPhysicsServiceProfile;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = HandPhysicsServiceProfile_get_HandPhysicsLayer_m9E5EBC77EC9B960FB18B65D94BF42F7EA8CA50C6_inline(L_0, NULL);
		HandPhysicsService_set_HandPhysicsLayer_m7BF4CB7E70EFB6CD80F3F77CBAE771716FF79ED0_inline(__this, L_1, NULL);
		HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* L_2 = __this->___handPhysicsServiceProfile;
		NullCheck(L_2);
		bool L_3;
		L_3 = HandPhysicsServiceProfile_get_UsePalmKinematicBody_m81F8E9FFACFE8A9C4140EFFFA03D47E40AAC3D9A_inline(L_2, NULL);
		HandPhysicsService_set_UsePalmKinematicBody_m67BE8E1211A0B1B165E25B82D3F879D409450694_inline(__this, L_3, NULL);
		HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* L_4 = __this->___handPhysicsServiceProfile;
		NullCheck(L_4);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5;
		L_5 = HandPhysicsServiceProfile_get_FingerTipKinematicBodyPrefab_m642AA6044A1D1F2E0BD7F19E840EC3201987A8AB_inline(L_4, NULL);
		HandPhysicsService_set_FingerTipKinematicBodyPrefab_m985C16BC725F354142C6B4E254C76476038FABE7(__this, L_5, NULL);
		HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* L_6 = __this->___handPhysicsServiceProfile;
		NullCheck(L_6);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_7;
		L_7 = HandPhysicsServiceProfile_get_PalmKinematicBodyPrefab_mE62F22D0A4E4DFE47FBF60A5C354D1150E90AF21_inline(L_6, NULL);
		HandPhysicsService_set_PalmKinematicBodyPrefab_mFE5C9BCCEACC998D31A8058EA4FC240FA324B6DB(__this, L_7, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_Enable_mE88081560985BC0AC04F45AFA3F039EBF447E741 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1D091D04287D4679285A2E663193C6F6B9AFDEAA);
		s_Il2CppMethodInitialized = true;
	}
	{
		BaseService_Enable_mF054160CA265761A1223A3F8CFE50A976C7297E8(__this, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88(L_0, _stringLiteral1D091D04287D4679285A2E663193C6F6B9AFDEAA, NULL);
		HandPhysicsService_set_HandPhysicsServiceRoot_m99C4CB7F02C191EB88579EA58D138D144030A892_inline(__this, L_0, NULL);
		HandPhysicsService_CreateKinematicBodies_mE673FFE4CDCFAB6546CB9DBFE3259D2E46B182A2(__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_Disable_m2CFBEAD6BC4DAEF4F527B7D6746AAC76291376D0 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0;
		L_0 = HandPhysicsService_get_HandPhysicsServiceRoot_mEDA47B73985CFE5593713DA7268AAB07C0321934_inline(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_0020;
		}
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
		L_2 = HandPhysicsService_get_HandPhysicsServiceRoot_mEDA47B73985CFE5593713DA7268AAB07C0321934_inline(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB(L_2, NULL);
		HandPhysicsService_set_HandPhysicsServiceRoot_m99C4CB7F02C191EB88579EA58D138D144030A892_inline(__this, (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)NULL, NULL);
	}

IL_0020:
	{
		BaseService_Disable_m75AA61136BE79E0C8EA4B058D1506882A56683C4(__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_Update_m0B85983AB28ED09B9C22B54DEBF4F6E7F949B8A7 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m8A20A8D117EA8E863E484FCBF3E5DF8B4F2DF6FE_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_mF5408289067372E7D77623ADFE1E7741F1ADADEA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mD3D72C58C7DBD2C1244CACC126D52940E0ADAE57_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityHandJointService_t335A41FECB2854EF54AEF3B6ABD1CAE631731895_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m70A301919477330858A06AE312F1ED809CCB9E72_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39 V_2;
	memset((&V_2), 0, sizeof(V_2));
	JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* V_3 = NULL;
	JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* G_B6_0 = NULL;
	JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* G_B5_0 = NULL;
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* G_B7_0 = NULL;
	JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* G_B7_1 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___UpdatePerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00a4:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			{
				BaseService_Update_m07A22E1552ABDCD9AD86737D12D43DA27915370D(__this, NULL);
				List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* L_2 = __this->___jointKinematicBodies;
				NullCheck(L_2);
				Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39 L_3;
				L_3 = List_1_GetEnumerator_m70A301919477330858A06AE312F1ED809CCB9E72(L_2, List_1_GetEnumerator_m70A301919477330858A06AE312F1ED809CCB9E72_RuntimeMethod_var);
				V_2 = L_3;
			}
			{
				auto __finallyBlock = il2cpp::utils::Finally([&]
				{

FINALLY_0096_1:
					{
						Enumerator_Dispose_m8A20A8D117EA8E863E484FCBF3E5DF8B4F2DF6FE((&V_2), Enumerator_Dispose_m8A20A8D117EA8E863E484FCBF3E5DF8B4F2DF6FE_RuntimeMethod_var);
						return;
					}
				});
				try
				{
					{
						goto IL_008b_2;
					}

IL_0022_2:
					{
						JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_4;
						L_4 = Enumerator_get_Current_mD3D72C58C7DBD2C1244CACC126D52940E0ADAE57_inline((&V_2), Enumerator_get_Current_mD3D72C58C7DBD2C1244CACC126D52940E0ADAE57_RuntimeMethod_var);
						V_3 = L_4;
						RuntimeObject* L_5;
						L_5 = HandPhysicsService_get_HandJointService_m69A7B84777D87F1E98C9557BAE7A446F6EF5C3AE(__this, NULL);
						JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_6 = V_3;
						NullCheck(L_6);
						uint8_t L_7;
						L_7 = JointKinematicBody_get_HandednessType_m77B12ADB2D2CD12BD3B0F4B6B88741489939CC9E_inline(L_6, NULL);
						NullCheck(L_5);
						bool L_8;
						L_8 = InterfaceFuncInvoker1< bool, uint8_t >::Invoke(1, IMixedRealityHandJointService_t335A41FECB2854EF54AEF3B6ABD1CAE631731895_il2cpp_TypeInfo_var, L_5, L_7);
						if (!L_8)
						{
							goto IL_0084_2;
						}
					}
					{
						JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_9 = V_3;
						JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_10 = V_3;
						NullCheck(L_10);
						Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_11;
						L_11 = JointKinematicBody_get_Joint_m7CD5366B9380ACAD28E0C3D9911375F99B40B3DD_inline(L_10, NULL);
						il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
						bool L_12;
						L_12 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_11, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
						if (L_12)
						{
							G_B6_0 = L_9;
							goto IL_0065_2;
						}
						G_B5_0 = L_9;
					}
					{
						RuntimeObject* L_13;
						L_13 = HandPhysicsService_get_HandJointService_m69A7B84777D87F1E98C9557BAE7A446F6EF5C3AE(__this, NULL);
						JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_14 = V_3;
						NullCheck(L_14);
						int32_t L_15;
						L_15 = JointKinematicBody_get_JointType_m73DC834B823F8BE1147C1C911B5572E9D2A45B33_inline(L_14, NULL);
						JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_16 = V_3;
						NullCheck(L_16);
						uint8_t L_17;
						L_17 = JointKinematicBody_get_HandednessType_m77B12ADB2D2CD12BD3B0F4B6B88741489939CC9E_inline(L_16, NULL);
						NullCheck(L_13);
						Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_18;
						L_18 = InterfaceFuncInvoker2< Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1*, int32_t, uint8_t >::Invoke(0, IMixedRealityHandJointService_t335A41FECB2854EF54AEF3B6ABD1CAE631731895_il2cpp_TypeInfo_var, L_13, L_15, L_17);
						G_B7_0 = L_18;
						G_B7_1 = G_B5_0;
						goto IL_006b_2;
					}

IL_0065_2:
					{
						JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_19 = V_3;
						NullCheck(L_19);
						Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_20;
						L_20 = JointKinematicBody_get_Joint_m7CD5366B9380ACAD28E0C3D9911375F99B40B3DD_inline(L_19, NULL);
						G_B7_0 = L_20;
						G_B7_1 = G_B6_0;
					}

IL_006b_2:
					{
						NullCheck(G_B7_1);
						JointKinematicBody_set_Joint_m9AA4BFBBC07572113292EC77A012F144B569164A_inline(G_B7_1, G_B7_0, NULL);
						JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_21 = V_3;
						JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_22 = V_3;
						NullCheck(L_22);
						Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_23;
						L_23 = JointKinematicBody_get_Joint_m7CD5366B9380ACAD28E0C3D9911375F99B40B3DD_inline(L_22, NULL);
						il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
						bool L_24;
						L_24 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_23, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
						NullCheck(L_21);
						JointKinematicBody_UpdateState_m3B4BF726E3531FD7A1FE46D8E4C80CFA81B9C6EA(L_21, L_24, NULL);
						goto IL_008b_2;
					}

IL_0084_2:
					{
						JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_25 = V_3;
						NullCheck(L_25);
						JointKinematicBody_UpdateState_m3B4BF726E3531FD7A1FE46D8E4C80CFA81B9C6EA(L_25, (bool)0, NULL);
					}

IL_008b_2:
					{
						bool L_26;
						L_26 = Enumerator_MoveNext_mF5408289067372E7D77623ADFE1E7741F1ADADEA((&V_2), Enumerator_MoveNext_mF5408289067372E7D77623ADFE1E7741F1ADADEA_RuntimeMethod_var);
						if (L_26)
						{
							goto IL_0022_2;
						}
					}
					{
						goto IL_00b2;
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

IL_00b2:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_CreateKinematicBodies_mE673FFE4CDCFAB6546CB9DBFE3259D2E46B182A2 (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m24FC1392D880374B2CB030D8742BDB1546E86FF3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* V_2 = NULL;
	JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* V_3 = NULL;
	{
		HandPhysicsService_DestroyKinematicBodies_mDB3070DCFE31CED79AAD71EFC0A35CD531812C5E(__this, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0;
		L_0 = HandPhysicsService_get_HandPhysicsServiceRoot_mEDA47B73985CFE5593713DA7268AAB07C0321934_inline(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		return;
	}

IL_0015:
	{
		V_0 = 0;
		goto IL_00c4;
	}

IL_001c:
	{
		V_1 = 0;
		goto IL_006c;
	}

IL_0020:
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
		L_2 = HandPhysicsService_get_FingerTipKinematicBodyPrefab_mDCEB71782ABC9AB74ED4E97F4066F3D535667A4D_inline(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_2, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (L_3)
		{
			goto IL_0068;
		}
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4;
		L_4 = HandPhysicsService_get_FingerTipKinematicBodyPrefab_mDCEB71782ABC9AB74ED4E97F4066F3D535667A4D_inline(__this, NULL);
		int32_t L_5;
		L_5 = HandPhysicsService_get_HandPhysicsLayer_m0F8368510837B9E4B871D09A7A6DAEB09FB4D4E4_inline(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var);
		HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E* L_6 = ((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___handednessTypes;
		int32_t L_7 = V_0;
		NullCheck(L_6);
		int32_t L_8 = L_7;
		uint8_t L_9 = (uint8_t)(L_6)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915* L_10 = ((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___fingerTipTypes;
		int32_t L_11 = V_1;
		NullCheck(L_10);
		int32_t L_12 = L_11;
		int32_t L_13 = (int32_t)(L_10)->GetAt(static_cast<il2cpp_array_size_t>(L_12));
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_14;
		L_14 = HandPhysicsService_get_HandPhysicsServiceRoot_mEDA47B73985CFE5593713DA7268AAB07C0321934_inline(__this, NULL);
		NullCheck(L_14);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_15;
		L_15 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_14, NULL);
		bool L_16;
		L_16 = HandPhysicsService_TryCreateJointKinematicBody_m4B9D0F1B46E1BC215BA1B5436302641C747B9E66(L_4, L_5, L_9, L_13, L_15, (&V_2), NULL);
		if (!L_16)
		{
			goto IL_0068;
		}
	}
	{
		List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* L_17 = __this->___jointKinematicBodies;
		JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_18 = V_2;
		NullCheck(L_17);
		List_1_Add_m24FC1392D880374B2CB030D8742BDB1546E86FF3_inline(L_17, L_18, List_1_Add_m24FC1392D880374B2CB030D8742BDB1546E86FF3_RuntimeMethod_var);
	}

IL_0068:
	{
		int32_t L_19 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_19, 1));
	}

IL_006c:
	{
		int32_t L_20 = V_1;
		il2cpp_codegen_runtime_class_init_inline(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var);
		TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915* L_21 = ((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___fingerTipTypes;
		NullCheck(L_21);
		if ((((int32_t)L_20) < ((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length)))))
		{
			goto IL_0020;
		}
	}
	{
		bool L_22;
		L_22 = HandPhysicsService_get_UsePalmKinematicBody_mBB0C082F0A6D6CB2603F308881440016BEC4083A_inline(__this, NULL);
		if (!L_22)
		{
			goto IL_00c0;
		}
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_23;
		L_23 = HandPhysicsService_get_PalmKinematicBodyPrefab_m8F15CD10E8BE3A1F0BEE38027CFB41F265F8BE5F_inline(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_24;
		L_24 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_23, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (L_24)
		{
			goto IL_00c0;
		}
	}
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_25;
		L_25 = HandPhysicsService_get_PalmKinematicBodyPrefab_m8F15CD10E8BE3A1F0BEE38027CFB41F265F8BE5F_inline(__this, NULL);
		int32_t L_26;
		L_26 = HandPhysicsService_get_HandPhysicsLayer_m0F8368510837B9E4B871D09A7A6DAEB09FB4D4E4_inline(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var);
		HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E* L_27 = ((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___handednessTypes;
		int32_t L_28 = V_0;
		NullCheck(L_27);
		int32_t L_29 = L_28;
		uint8_t L_30 = (uint8_t)(L_27)->GetAt(static_cast<il2cpp_array_size_t>(L_29));
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_31;
		L_31 = HandPhysicsService_get_HandPhysicsServiceRoot_mEDA47B73985CFE5593713DA7268AAB07C0321934_inline(__this, NULL);
		NullCheck(L_31);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_32;
		L_32 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_31, NULL);
		bool L_33;
		L_33 = HandPhysicsService_TryCreateJointKinematicBody_m4B9D0F1B46E1BC215BA1B5436302641C747B9E66(L_25, L_26, L_30, 2, L_32, (&V_3), NULL);
		if (!L_33)
		{
			goto IL_00c0;
		}
	}
	{
		List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* L_34 = __this->___jointKinematicBodies;
		JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_35 = V_3;
		NullCheck(L_34);
		List_1_Add_m24FC1392D880374B2CB030D8742BDB1546E86FF3_inline(L_34, L_35, List_1_Add_m24FC1392D880374B2CB030D8742BDB1546E86FF3_RuntimeMethod_var);
	}

IL_00c0:
	{
		int32_t L_36 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_36, 1));
	}

IL_00c4:
	{
		int32_t L_37 = V_0;
		il2cpp_codegen_runtime_class_init_inline(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var);
		HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E* L_38 = ((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___handednessTypes;
		NullCheck(L_38);
		if ((((int32_t)L_37) < ((int32_t)((int32_t)(((RuntimeArray*)L_38)->max_length)))))
		{
			goto IL_001c;
		}
	}
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService_DestroyKinematicBodies_mDB3070DCFE31CED79AAD71EFC0A35CD531812C5E (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m8A20A8D117EA8E863E484FCBF3E5DF8B4F2DF6FE_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_mF5408289067372E7D77623ADFE1E7741F1ADADEA_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mD3D72C58C7DBD2C1244CACC126D52940E0ADAE57_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_GetEnumerator_m70A301919477330858A06AE312F1ED809CCB9E72_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m0AD894688377C5604795014FBCA9A265B896B417_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* L_0 = __this->___jointKinematicBodies;
		NullCheck(L_0);
		int32_t L_1;
		L_1 = List_1_get_Count_m0AD894688377C5604795014FBCA9A265B896B417_inline(L_0, List_1_get_Count_m0AD894688377C5604795014FBCA9A265B896B417_RuntimeMethod_var);
		if ((((int32_t)L_1) <= ((int32_t)0)))
		{
			goto IL_0046;
		}
	}
	{
		List_1_tC338922AA7C777DFC2B86B43F8B7E0EE1954A29E* L_2 = __this->___jointKinematicBodies;
		NullCheck(L_2);
		Enumerator_t8A74C6BB72E340D570BE9E3C2AB0ADD9D6C51B39 L_3;
		L_3 = List_1_GetEnumerator_m70A301919477330858A06AE312F1ED809CCB9E72(L_2, List_1_GetEnumerator_m70A301919477330858A06AE312F1ED809CCB9E72_RuntimeMethod_var);
		V_0 = L_3;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0038:
			{
				Enumerator_Dispose_m8A20A8D117EA8E863E484FCBF3E5DF8B4F2DF6FE((&V_0), Enumerator_Dispose_m8A20A8D117EA8E863E484FCBF3E5DF8B4F2DF6FE_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_002d_1;
			}

IL_001c_1:
			{
				JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_4;
				L_4 = Enumerator_get_Current_mD3D72C58C7DBD2C1244CACC126D52940E0ADAE57_inline((&V_0), Enumerator_get_Current_mD3D72C58C7DBD2C1244CACC126D52940E0ADAE57_RuntimeMethod_var);
				NullCheck(L_4);
				GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5;
				L_5 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_4, NULL);
				il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
				Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB(L_5, NULL);
			}

IL_002d_1:
			{
				bool L_6;
				L_6 = Enumerator_MoveNext_mF5408289067372E7D77623ADFE1E7741F1ADADEA((&V_0), Enumerator_MoveNext_mF5408289067372E7D77623ADFE1E7741F1ADADEA_RuntimeMethod_var);
				if (L_6)
				{
					goto IL_001c_1;
				}
			}
			{
				goto IL_0046;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0046:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HandPhysicsService_TryCreateJointKinematicBody_m4B9D0F1B46E1BC215BA1B5436302641C747B9E66 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_rigidBodyPrefab, int32_t ___1_layer, uint8_t ___2_handednessType, int32_t ___3_jointType, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___4_parent, JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E** ___5_jointKinematicBody, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_GetComponent_TisCollider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76_m4CB0FC4E59CE6C91F1106739EF364208A63E2597_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_GetComponent_TisJointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_mDC52B1A4AFD97A35D7CC54CE006568DC2F65A3D5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_GetComponent_TisRigidbody_t268697F5A994213ED97393309870968BC1C7393C_m2D7F86C77ECF9B82AAC077B511F1004280571B90_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Handedness_t8F3D346D04DED9C8F19FDD0EAB3DFFF385E485FF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m58C654F1134533E29502629CA67645682B404811_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackedHandJoint_tEDCBD4B9A65BBB59D6C182873CEF88E1A12A356B_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1B7C657456EEB67D39103E7D53301AB040007E6F);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2CA525E745821399EEF6F1D2733A285A82160939);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA498934C25635BF965454E7B0EFC76A87F36A1B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE32213B913E2692579F46DFC5F32A1E135F596B6);
		s_Il2CppMethodInitialized = true;
	}
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* V_0 = NULL;
	JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* V_1 = NULL;
	Rigidbody_t268697F5A994213ED97393309870968BC1C7393C* V_2 = NULL;
	{
		JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E** L_0 = ___5_jointKinematicBody;
		*((RuntimeObject**)L_0) = (RuntimeObject*)NULL;
		Il2CppCodeGenWriteBarrier((void**)(RuntimeObject**)L_0, (void*)(RuntimeObject*)NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_1 = ___0_rigidBodyPrefab;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2 = ___4_parent;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3;
		L_3 = Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m58C654F1134533E29502629CA67645682B404811(L_1, L_2, Object_Instantiate_TisGameObject_t76FEDD663AB33C991A9C9A23129337651094216F_m58C654F1134533E29502629CA67645682B404811_RuntimeMethod_var);
		V_0 = L_3;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4 = V_0;
		int32_t L_5 = ___1_layer;
		NullCheck(L_4);
		GameObject_set_layer_m6E1AF478A2CC86BD222B96317BEB78B7D89B18D0(L_4, L_5, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_6 = V_0;
		NullCheck(L_6);
		JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_7;
		L_7 = GameObject_GetComponent_TisJointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_mDC52B1A4AFD97A35D7CC54CE006568DC2F65A3D5(L_6, GameObject_GetComponent_TisJointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_mDC52B1A4AFD97A35D7CC54CE006568DC2F65A3D5_RuntimeMethod_var);
		V_1 = L_7;
		JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_8 = V_1;
		bool L_9;
		L_9 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_8, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_9)
		{
			goto IL_0036;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteralDA498934C25635BF965454E7B0EFC76A87F36A1B, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_10 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB(L_10, NULL);
		return (bool)0;
	}

IL_0036:
	{
		JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_11 = V_1;
		int32_t L_12 = ___3_jointType;
		NullCheck(L_11);
		JointKinematicBody_set_JointType_m7C023561616D22CFEEA796AB2D9334BDA6A0FAD0_inline(L_11, L_12, NULL);
		JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_13 = V_1;
		uint8_t L_14 = ___2_handednessType;
		NullCheck(L_13);
		JointKinematicBody_set_HandednessType_m894E251DC1625B3DAF1478896419E4551C5E6E5B_inline(L_13, L_14, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_15 = V_0;
		Il2CppFakeBox<uint8_t> L_16(Handedness_t8F3D346D04DED9C8F19FDD0EAB3DFFF385E485FF_il2cpp_TypeInfo_var, (&___2_handednessType));
		String_t* L_17;
		L_17 = Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741((Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2*)(&L_16), NULL);
		Il2CppFakeBox<int32_t> L_18(TrackedHandJoint_tEDCBD4B9A65BBB59D6C182873CEF88E1A12A356B_il2cpp_TypeInfo_var, (&___3_jointType));
		String_t* L_19;
		L_19 = Enum_ToString_m946B0B83C4470457D0FF555D862022C72BB55741((Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2*)(&L_18), NULL);
		String_t* L_20;
		L_20 = String_Concat_m8855A6DE10F84DA7F4EC113CADDB59873A25573B(L_17, _stringLiteral2386E77CF610F786B06A91AF2C1B3FD2282D2745, L_19, NULL);
		NullCheck(L_15);
		Object_set_name_mC79E6DC8FFD72479C90F0C4CC7F42A0FEAF5AE47(L_15, L_20, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_21 = V_0;
		NullCheck(L_21);
		Collider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76* L_22;
		L_22 = GameObject_GetComponent_TisCollider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76_m4CB0FC4E59CE6C91F1106739EF364208A63E2597(L_21, GameObject_GetComponent_TisCollider_t1CC3163924FCD6C4CC2E816373A929C1E3D55E76_m4CB0FC4E59CE6C91F1106739EF364208A63E2597_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_23;
		L_23 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_22, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_23)
		{
			goto IL_008e;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteral1B7C657456EEB67D39103E7D53301AB040007E6F, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_24 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB(L_24, NULL);
		return (bool)0;
	}

IL_008e:
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_25 = V_0;
		NullCheck(L_25);
		Rigidbody_t268697F5A994213ED97393309870968BC1C7393C* L_26;
		L_26 = GameObject_GetComponent_TisRigidbody_t268697F5A994213ED97393309870968BC1C7393C_m2D7F86C77ECF9B82AAC077B511F1004280571B90(L_25, GameObject_GetComponent_TisRigidbody_t268697F5A994213ED97393309870968BC1C7393C_m2D7F86C77ECF9B82AAC077B511F1004280571B90_RuntimeMethod_var);
		V_2 = L_26;
		Rigidbody_t268697F5A994213ED97393309870968BC1C7393C* L_27 = V_2;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_28;
		L_28 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_27, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_28)
		{
			goto IL_00b0;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(_stringLiteralE32213B913E2692579F46DFC5F32A1E135F596B6, NULL);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_29 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_Destroy_mE97D0A766419A81296E8D4E5C23D01D3FE91ACBB(L_29, NULL);
		return (bool)0;
	}

IL_00b0:
	{
		Rigidbody_t268697F5A994213ED97393309870968BC1C7393C* L_30 = V_2;
		NullCheck(L_30);
		bool L_31;
		L_31 = Rigidbody_get_isKinematic_mC20906CA5A89983DE06EAC6E3AFC5BC012F90CA1(L_30, NULL);
		if (L_31)
		{
			goto IL_00c9;
		}
	}
	{
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(_stringLiteral2CA525E745821399EEF6F1D2733A285A82160939, NULL);
		Rigidbody_t268697F5A994213ED97393309870968BC1C7393C* L_32 = V_2;
		NullCheck(L_32);
		Rigidbody_set_isKinematic_m6C3FD3EA358DADA3B191F2449CF1C4F8B22695ED(L_32, (bool)1, NULL);
	}

IL_00c9:
	{
		JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E** L_33 = ___5_jointKinematicBody;
		JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* L_34 = V_1;
		*((RuntimeObject**)L_33) = (RuntimeObject*)L_34;
		Il2CppCodeGenWriteBarrier((void**)(RuntimeObject**)L_33, (void*)(RuntimeObject*)L_34);
		return (bool)1;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsService__cctor_m3E03A31B872A566946E1471A4B7DFE0EC508748B (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99____3F88FBB7FD9DDD81E9E2A619815356D8409B35AEFD4F2B0F9CD9473E251D468B_FieldInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1C7FAA54D286D9BC344C94963A928369C13F9604);
		s_Il2CppMethodInitialized = true;
	}
	{
		HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E* L_0 = (HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E*)(HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E*)SZArrayNew(HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E_il2cpp_TypeInfo_var, (uint32_t)2);
		HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E* L_1 = L_0;
		NullCheck(L_1);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(0), (uint8_t)1);
		HandednessU5BU5D_t71664ED11900AE705EFA0B82692250AA8CEC139E* L_2 = L_1;
		NullCheck(L_2);
		(L_2)->SetAt(static_cast<il2cpp_array_size_t>(1), (uint8_t)2);
		((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___handednessTypes = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___handednessTypes), (void*)L_2);
		TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915* L_3 = (TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915*)(TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915*)SZArrayNew(TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915_il2cpp_TypeInfo_var, (uint32_t)5);
		TrackedHandJointU5BU5D_t1BBC5815AB763BFF0800344D0533B21FBBC07915* L_4 = L_3;
		RuntimeFieldHandle_t6E4C45B6D2EA12FC99185805A7E77527899B25C5 L_5 = { reinterpret_cast<intptr_t> (U3CPrivateImplementationDetailsU3E_tEA0A612796236EFDB05BFA31A3500BDF90F0BB99____3F88FBB7FD9DDD81E9E2A619815356D8409B35AEFD4F2B0F9CD9473E251D468B_FieldInfo_var) };
		RuntimeHelpers_InitializeArray_m751372AA3F24FBF6DA9B9D687CBFA2DE436CAB9B((RuntimeArray*)L_4, L_5, NULL);
		((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___fingerTipTypes = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___fingerTipTypes), (void*)L_4);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_6;
		memset((&L_6), 0, sizeof(L_6));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_6), _stringLiteral1C7FAA54D286D9BC344C94963A928369C13F9604, NULL);
		((HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_StaticFields*)il2cpp_codegen_static_fields_for(HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890_il2cpp_TypeInfo_var))->___UpdatePerfMarker = L_6;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool HandPhysicsServiceProfile_get_UsePalmKinematicBody_m81F8E9FFACFE8A9C4140EFFFA03D47E40AAC3D9A (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___usePalmKinematicBody;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsServiceProfile_get_FingerTipKinematicBodyPrefab_m642AA6044A1D1F2E0BD7F19E840EC3201987A8AB (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___fingerTipKinematicBodyPrefab;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsServiceProfile_get_PalmKinematicBodyPrefab_mE62F22D0A4E4DFE47FBF60A5C354D1150E90AF21 (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___palmKinematicBodyPrefab;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t HandPhysicsServiceProfile_get_HandPhysicsLayer_m9E5EBC77EC9B960FB18B65D94BF42F7EA8CA50C6 (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___handPhysicsLayer;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void HandPhysicsServiceProfile__ctor_m0EDB1DF4A3F99C79F7C206A79254E895C590889A (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) 
{
	{
		BaseMixedRealityProfile__ctor_mE6D5359B74BAAEA74B1F24297F435C969CD43DFE(__this, NULL);
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* JointKinematicBody_get_Joint_m7CD5366B9380ACAD28E0C3D9911375F99B40B3DD (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0 = __this->___U3CJointU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void JointKinematicBody_set_Joint_m9AA4BFBBC07572113292EC77A012F144B569164A (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___0_value, const RuntimeMethod* method) 
{
	{
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0 = ___0_value;
		__this->___U3CJointU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CJointU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR uint8_t JointKinematicBody_get_HandednessType_m77B12ADB2D2CD12BD3B0F4B6B88741489939CC9E (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		uint8_t L_0 = __this->___U3CHandednessTypeU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void JointKinematicBody_set_HandednessType_m894E251DC1625B3DAF1478896419E4551C5E6E5B (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, uint8_t ___0_value, const RuntimeMethod* method) 
{
	{
		uint8_t L_0 = ___0_value;
		__this->___U3CHandednessTypeU3Ek__BackingField = L_0;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t JointKinematicBody_get_JointType_m73DC834B823F8BE1147C1C911B5572E9D2A45B33 (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CJointTypeU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void JointKinematicBody_set_JointType_m7C023561616D22CFEEA796AB2D9334BDA6A0FAD0 (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->___U3CJointTypeU3Ek__BackingField = L_0;
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* JointKinematicBody_get_OnEnableAction_m3F01CA478D48E1BF10E3F82617AFE23694C3EB96 (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* L_0 = __this->___U3COnEnableActionU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void JointKinematicBody_set_OnEnableAction_mB07C682F6F472970AA144925E7E21488B9BA2F15 (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* ___0_value, const RuntimeMethod* method) 
{
	{
		Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* L_0 = ___0_value;
		__this->___U3COnEnableActionU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3COnEnableActionU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* JointKinematicBody_get_OnDisableAction_m5B477E4517FBEA9D2518C9F7823EE43C8C511223 (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* L_0 = __this->___U3COnDisableActionU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void JointKinematicBody_set_OnDisableAction_m73D98BF3C7954434F2AF4A306A1773BB5E1A4552 (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* ___0_value, const RuntimeMethod* method) 
{
	{
		Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* L_0 = ___0_value;
		__this->___U3COnDisableActionU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3COnDisableActionU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void JointKinematicBody_UpdateState_m3B4BF726E3531FD7A1FE46D8E4C80CFA81B9C6EA (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, bool ___0_active, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	bool G_B3_0 = false;
	bool G_B2_0 = false;
	Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* G_B7_0 = NULL;
	Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* G_B6_0 = NULL;
	Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* G_B10_0 = NULL;
	Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* G_B9_0 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_StaticFields*)il2cpp_codegen_static_fields_for(JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_il2cpp_TypeInfo_var))->___UpdateStatePerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0082:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			{
				GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
				L_2 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(__this, NULL);
				NullCheck(L_2);
				bool L_3;
				L_3 = GameObject_get_activeSelf_m4F3E5240E138B66AAA080EA30759A3D0517DA368(L_2, NULL);
				GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_4;
				L_4 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(__this, NULL);
				bool L_5 = ___0_active;
				NullCheck(L_4);
				GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_4, L_5, NULL);
				bool L_6 = ___0_active;
				if (!L_6)
				{
					G_B3_0 = L_3;
					goto IL_0054_1;
				}
				G_B2_0 = L_3;
			}
			{
				Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_7;
				L_7 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
				Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_8;
				L_8 = JointKinematicBody_get_Joint_m7CD5366B9380ACAD28E0C3D9911375F99B40B3DD_inline(__this, NULL);
				NullCheck(L_8);
				Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9;
				L_9 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_8, NULL);
				NullCheck(L_7);
				Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156(L_7, L_9, NULL);
				Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_10;
				L_10 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
				Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_11;
				L_11 = JointKinematicBody_get_Joint_m7CD5366B9380ACAD28E0C3D9911375F99B40B3DD_inline(__this, NULL);
				NullCheck(L_11);
				Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_12;
				L_12 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_11, NULL);
				NullCheck(L_10);
				Transform_set_rotation_m61340DE74726CF0F9946743A727C4D444397331D(L_10, L_12, NULL);
				G_B3_0 = G_B2_0;
			}

IL_0054_1:
			{
				bool L_13 = ___0_active;
				if ((((int32_t)G_B3_0) == ((int32_t)L_13)))
				{
					goto IL_0080_1;
				}
			}
			{
				bool L_14 = ___0_active;
				if (!L_14)
				{
					goto IL_006e_1;
				}
			}
			{
				Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* L_15;
				L_15 = JointKinematicBody_get_OnEnableAction_m3F01CA478D48E1BF10E3F82617AFE23694C3EB96_inline(__this, NULL);
				Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* L_16 = L_15;
				if (L_16)
				{
					G_B7_0 = L_16;
					goto IL_0066_1;
				}
				G_B6_0 = L_16;
			}
			{
				goto IL_0090;
			}

IL_0066_1:
			{
				NullCheck(G_B7_0);
				Action_1_Invoke_m04C0747C16026AF8A583ADA4927B57C5426E544F_inline(G_B7_0, __this, NULL);
				goto IL_0090;
			}

IL_006e_1:
			{
				Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* L_17;
				L_17 = JointKinematicBody_get_OnDisableAction_m5B477E4517FBEA9D2518C9F7823EE43C8C511223_inline(__this, NULL);
				Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* L_18 = L_17;
				if (L_18)
				{
					G_B10_0 = L_18;
					goto IL_007a_1;
				}
				G_B9_0 = L_18;
			}
			{
				goto IL_0090;
			}

IL_007a_1:
			{
				NullCheck(G_B10_0);
				Action_1_Invoke_m04C0747C16026AF8A583ADA4927B57C5426E544F_inline(G_B10_0, __this, NULL);
			}

IL_0080_1:
			{
				goto IL_0090;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0090:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void JointKinematicBody__ctor_m72761A78EF673D5B8AAC1E36399FAA3CAFA8BA0B (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void JointKinematicBody__cctor_m505F51179A2259FA42DD8E3226F52AAE5ABF49B4 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC1738C3F31C42EB3867F885AD91436A640396392);
		s_Il2CppMethodInitialized = true;
	}
	{
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0;
		memset((&L_0), 0, sizeof(L_0));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_0), _stringLiteralC1738C3F31C42EB3867F885AD91436A640396392, NULL);
		((JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_StaticFields*)il2cpp_codegen_static_fields_for(JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E_il2cpp_TypeInfo_var))->___UpdateStatePerfMarker = L_0;
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
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HandPhysicsServiceProfile_get_HandPhysicsLayer_m9E5EBC77EC9B960FB18B65D94BF42F7EA8CA50C6_inline (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___handPhysicsLayer;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void HandPhysicsService_set_HandPhysicsLayer_m7BF4CB7E70EFB6CD80F3F77CBAE771716FF79ED0_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->___U3CHandPhysicsLayerU3Ek__BackingField = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool HandPhysicsServiceProfile_get_UsePalmKinematicBody_m81F8E9FFACFE8A9C4140EFFFA03D47E40AAC3D9A_inline (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___usePalmKinematicBody;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void HandPhysicsService_set_UsePalmKinematicBody_m67BE8E1211A0B1B165E25B82D3F879D409450694_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		bool L_0 = ___0_value;
		__this->___U3CUsePalmKinematicBodyU3Ek__BackingField = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsServiceProfile_get_FingerTipKinematicBodyPrefab_m642AA6044A1D1F2E0BD7F19E840EC3201987A8AB_inline (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___fingerTipKinematicBodyPrefab;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsServiceProfile_get_PalmKinematicBodyPrefab_mE62F22D0A4E4DFE47FBF60A5C354D1150E90AF21_inline (HandPhysicsServiceProfile_tBDFE50F749D6AE0A58C5546AA0DB0C4499E490BD* __this, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___palmKinematicBodyPrefab;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void HandPhysicsService_set_HandPhysicsServiceRoot_m99C4CB7F02C191EB88579EA58D138D144030A892_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___0_value, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = ___0_value;
		__this->___U3CHandPhysicsServiceRootU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CHandPhysicsServiceRootU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsService_get_HandPhysicsServiceRoot_mEDA47B73985CFE5593713DA7268AAB07C0321934_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___U3CHandPhysicsServiceRootU3Ek__BackingField;
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR uint8_t JointKinematicBody_get_HandednessType_m77B12ADB2D2CD12BD3B0F4B6B88741489939CC9E_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		uint8_t L_0 = __this->___U3CHandednessTypeU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* JointKinematicBody_get_Joint_m7CD5366B9380ACAD28E0C3D9911375F99B40B3DD_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0 = __this->___U3CJointU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t JointKinematicBody_get_JointType_m73DC834B823F8BE1147C1C911B5572E9D2A45B33_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CJointTypeU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void JointKinematicBody_set_Joint_m9AA4BFBBC07572113292EC77A012F144B569164A_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___0_value, const RuntimeMethod* method) 
{
	{
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0 = ___0_value;
		__this->___U3CJointU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CJointU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsService_get_FingerTipKinematicBodyPrefab_mDCEB71782ABC9AB74ED4E97F4066F3D535667A4D_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___fingerTipKinematicBodyPrefab;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t HandPhysicsService_get_HandPhysicsLayer_m0F8368510837B9E4B871D09A7A6DAEB09FB4D4E4_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CHandPhysicsLayerU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool HandPhysicsService_get_UsePalmKinematicBody_mBB0C082F0A6D6CB2603F308881440016BEC4083A_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___U3CUsePalmKinematicBodyU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* HandPhysicsService_get_PalmKinematicBodyPrefab_m8F15CD10E8BE3A1F0BEE38027CFB41F265F8BE5F_inline (HandPhysicsService_t1D77FB4AFC9703B596EE3C4D47216970FBCAA890* __this, const RuntimeMethod* method) 
{
	{
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_0 = __this->___palmKinematicBodyPrefab;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void JointKinematicBody_set_JointType_m7C023561616D22CFEEA796AB2D9334BDA6A0FAD0_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->___U3CJointTypeU3Ek__BackingField = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void JointKinematicBody_set_HandednessType_m894E251DC1625B3DAF1478896419E4551C5E6E5B_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, uint8_t ___0_value, const RuntimeMethod* method) 
{
	{
		uint8_t L_0 = ___0_value;
		__this->___U3CHandednessTypeU3Ek__BackingField = L_0;
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* JointKinematicBody_get_OnEnableAction_m3F01CA478D48E1BF10E3F82617AFE23694C3EB96_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* L_0 = __this->___U3COnEnableActionU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* JointKinematicBody_get_OnDisableAction_m5B477E4517FBEA9D2518C9F7823EE43C8C511223_inline (JointKinematicBody_tE1AB63485D89F999D07005C192C5AF83AD5B664E* __this, const RuntimeMethod* method) 
{
	{
		Action_1_t995395EA370D4912CA4CBEF7089ED9405327F340* L_0 = __this->___U3COnDisableActionU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m6330F15D18EE4F547C05DF9BF83C5EB710376027_gshared_inline (Enumerator_t9473BAB568A27E2339D48C1F91319E0F6D244D7A* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->____current;
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Action_1_Invoke_mF2422B2DD29F74CE66F791C3F68E288EC7C3DB9E_gshared_inline (Action_1_t6F9EB113EB3F16226AEF811A2744F4111C116C87* __this, RuntimeObject* ___0_obj, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, RuntimeObject*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl)((Il2CppObject*)__this->___method_code, ___0_obj, reinterpret_cast<RuntimeMethod*>(__this->___method));
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
