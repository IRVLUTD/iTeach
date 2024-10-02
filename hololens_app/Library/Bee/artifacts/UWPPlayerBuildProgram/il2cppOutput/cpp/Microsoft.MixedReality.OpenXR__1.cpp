#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


struct GenericInterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (const RuntimeMethod* method, RuntimeObject* obj)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_interface_invoke_data(method, obj, &invokeData);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1, typename T2>
struct GenericInterfaceActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const RuntimeMethod*);

	static inline void Invoke (const RuntimeMethod* method, RuntimeObject* obj, T1 p1, T2 p2)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_interface_invoke_data(method, obj, &invokeData);
		((Action)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
	}
};

struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
struct List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35;
struct XRMarkerSubsystemDescriptorU5BU5D_t29D66BBA61AEC7558FAAA08A31214A92ED40E64D;
struct IOpenXRContext_t9516AC31F508ED22DB3791D6A9A88C9963328263;
struct ISubsystemPlugin_t40FA6639F1F57974DC348B62EA2DCE1A8EB74B82;
struct MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7;
struct String_t;
struct SubsystemController_tD5980C0FF070149F54AC1C113942441FCC0A69BF;

IL2CPP_EXTERN_C RuntimeClass* List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral0DE17B7149CFC4AD2D8D4499DED4098286557720;
IL2CPP_EXTERN_C String_t* _stringLiteral23DC94C1A21957C047FE1EB19F86F440997C76E7;
IL2CPP_EXTERN_C const RuntimeMethod* ISubsystemPlugin_CreateSubsystem_TisXRMarkerSubsystemDescriptor_t715496976A18AD6956A17832EEF59785900C0DD6_TisXRMarkerSubsystem_t5233A26F1CE4D4DD3DFCCCFC32FDA9C4D992A357_m1A23BDF123AF771DE0E0D8BC99000A2698E7D48A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ISubsystemPlugin_DestroySubsystem_TisXRMarkerSubsystem_t5233A26F1CE4D4DD3DFCCCFC32FDA9C4D992A357_m29E429B7340A8A442182BD2DAA371BE7A9443B36_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_mC591BF6C7964B9359D62D7D0BD6AD4461C35F580_RuntimeMethod_var;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35  : public RuntimeObject
{
	XRMarkerSubsystemDescriptorU5BU5D_t29D66BBA61AEC7558FAAA08A31214A92ED40E64D* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct U3CPrivateImplementationDetailsU3E_t228A994DA42421786B951FED157E05FA7A1B2655  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct SubsystemController_tD5980C0FF070149F54AC1C113942441FCC0A69BF  : public RuntimeObject
{
	RuntimeObject* ___Context;
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
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7  : public SubsystemController_tD5980C0FF070149F54AC1C113942441FCC0A69BF
{
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
struct __StaticArrayInitTypeSizeU3D6473_tCE344DBCAFE766A2A6DECBA7D53FF850B430266A 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D6473_tCE344DBCAFE766A2A6DECBA7D53FF850B430266A__padding[6473];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D6755_tC600324D95D5CCE924713A5BAA0BB564781BFC96 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D6755_tC600324D95D5CCE924713A5BAA0BB564781BFC96__padding[6755];
	};
};
#pragma pack(pop, tp)
struct List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35_StaticFields
{
	XRMarkerSubsystemDescriptorU5BU5D_t29D66BBA61AEC7558FAAA08A31214A92ED40E64D* ___s_emptyArray;
};
struct U3CPrivateImplementationDetailsU3E_t228A994DA42421786B951FED157E05FA7A1B2655_StaticFields
{
	__StaticArrayInitTypeSizeU3D6755_tC600324D95D5CCE924713A5BAA0BB564781BFC96 ___82C371BE4ED829F0AF4C54CE9FDA9B3615D76261AA3356EACFD7A9FD98241A5C;
	__StaticArrayInitTypeSizeU3D6473_tCE344DBCAFE766A2A6DECBA7D53FF850B430266A ___A5DB7C0E61F13BFFAF0894DBEEA52C593E016525A4345026157D9FA9948B001D;
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
struct MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_StaticFields
{
	List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35* ___s_MarkerDescriptors;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif


IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SubsystemController__ctor_m860DC323501E43007757630E4E5AE907CC3DBBA4 (SubsystemController_tD5980C0FF070149F54AC1C113942441FCC0A69BF* __this, RuntimeObject* ___0_context, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool OpenXRRuntime_IsExtensionEnabled_mF0C6FC95EDFD8DA6C5A838EA2053C06F657A2EE5 (String_t* ___0_extensionName, const RuntimeMethod* method) ;
inline void List_1__ctor_mC591BF6C7964B9359D62D7D0BD6AD4461C35F580 (List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MarkerSubsystemController__ctor_mE834221E79C5A9097B7294175A4A96B05B912DBC (MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7* __this, RuntimeObject* ___0_context, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_context;
		SubsystemController__ctor_m860DC323501E43007757630E4E5AE907CC3DBBA4(__this, L_0, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MarkerSubsystemController_OnSubsystemCreate_m63487805481D8DAE4482D8121087105B6876F5D8 (MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7* __this, RuntimeObject* ___0_plugin, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ISubsystemPlugin_CreateSubsystem_TisXRMarkerSubsystemDescriptor_t715496976A18AD6956A17832EEF59785900C0DD6_TisXRMarkerSubsystem_t5233A26F1CE4D4DD3DFCCCFC32FDA9C4D992A357_m1A23BDF123AF771DE0E0D8BC99000A2698E7D48A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0DE17B7149CFC4AD2D8D4499DED4098286557720);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral23DC94C1A21957C047FE1EB19F86F440997C76E7);
		s_Il2CppMethodInitialized = true;
	}
	{
		bool L_0;
		L_0 = OpenXRRuntime_IsExtensionEnabled_mF0C6FC95EDFD8DA6C5A838EA2053C06F657A2EE5(_stringLiteral23DC94C1A21957C047FE1EB19F86F440997C76E7, NULL);
		if (!L_0)
		{
			goto IL_001c;
		}
	}
	{
		RuntimeObject* L_1 = ___0_plugin;
		il2cpp_codegen_runtime_class_init_inline(MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_il2cpp_TypeInfo_var);
		List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35* L_2 = ((MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_StaticFields*)il2cpp_codegen_static_fields_for(MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_il2cpp_TypeInfo_var))->___s_MarkerDescriptors;
		NullCheck(L_1);
		GenericInterfaceActionInvoker2< List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35*, String_t* >::Invoke(ISubsystemPlugin_CreateSubsystem_TisXRMarkerSubsystemDescriptor_t715496976A18AD6956A17832EEF59785900C0DD6_TisXRMarkerSubsystem_t5233A26F1CE4D4DD3DFCCCFC32FDA9C4D992A357_m1A23BDF123AF771DE0E0D8BC99000A2698E7D48A_RuntimeMethod_var, L_1, L_2, _stringLiteral0DE17B7149CFC4AD2D8D4499DED4098286557720);
	}

IL_001c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MarkerSubsystemController_OnSubsystemDestroy_m7784FD85FB3DFF1ADD45A5D92E9779490BE5208D (MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7* __this, RuntimeObject* ___0_plugin, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ISubsystemPlugin_DestroySubsystem_TisXRMarkerSubsystem_t5233A26F1CE4D4DD3DFCCCFC32FDA9C4D992A357_m29E429B7340A8A442182BD2DAA371BE7A9443B36_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = ___0_plugin;
		NullCheck(L_0);
		GenericInterfaceActionInvoker0::Invoke(ISubsystemPlugin_DestroySubsystem_TisXRMarkerSubsystem_t5233A26F1CE4D4DD3DFCCCFC32FDA9C4D992A357_m29E429B7340A8A442182BD2DAA371BE7A9443B36_RuntimeMethod_var, L_0);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MarkerSubsystemController__cctor_mE0C003AAFAEC4F66A9C97677AD06326098443E8B (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_mC591BF6C7964B9359D62D7D0BD6AD4461C35F580_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35* L_0 = (List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35*)il2cpp_codegen_object_new(List_1_tC22825AB237DE70BB25C7CB8743604D331C95C35_il2cpp_TypeInfo_var);
		List_1__ctor_mC591BF6C7964B9359D62D7D0BD6AD4461C35F580(L_0, List_1__ctor_mC591BF6C7964B9359D62D7D0BD6AD4461C35F580_RuntimeMethod_var);
		((MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_StaticFields*)il2cpp_codegen_static_fields_for(MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_il2cpp_TypeInfo_var))->___s_MarkerDescriptors = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_StaticFields*)il2cpp_codegen_static_fields_for(MarkerSubsystemController_t9FD2C3CD0E501738ED6930D1D649CF44D8547CC7_il2cpp_TypeInfo_var))->___s_MarkerDescriptors), (void*)L_0);
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
