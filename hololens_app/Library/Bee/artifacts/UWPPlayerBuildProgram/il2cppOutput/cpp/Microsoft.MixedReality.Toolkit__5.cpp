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
template <typename R, typename T1, typename T2>
struct VirtualFuncInvoker2
{
	typedef R (*Func)(void*, T1, T2, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1, T2 p2)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, invokeData.method);
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
template <typename R, typename T1, typename T2, typename T3>
struct InterfaceFuncInvoker3
{
	typedef R (*Func)(void*, T1, T2, T3, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj, T1 p1, T2 p2, T3 p3)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, p1, p2, p3, invokeData.method);
	}
};

struct BaseDataProvider_1_t1C7B9F1707FEB27659F53B230E0A18282D2F7F20;
struct BaseDataProvider_1_t8DC280A360428C68343AA5D6B95788F4A050196F;
struct Dictionary_2_t924EC80B88AF529C31B6BD658C27711A7B2B2A5E;
struct Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907;
struct Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659;
struct HashSet_1_tA6A38ACBB9B75A13510D4F82BD093B367BE4666E;
struct HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885;
struct IEqualityComparer_1_t1539A49033C3F5A4026435640F020A586A4589F5;
struct IEqualityComparer_1_tDBFC8496F14612776AF930DBF84AFE7D06D1F0E9;
struct KeyCollection_tE794D6DD1B21B8F7F22ED237E5E52CE02DC50C87;
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D;
struct List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647;
struct ValueCollection_tB296124607AD0E5448E6B9010FCA8DCA56C330EA;
struct EntryU5BU5D_t661D7AB2C7445EFBB9C8EAD4DE4F9BA7A240B62F;
struct SlotU5BU5D_t5352D3708E20A120FCB9C071207F940FB2F2C004;
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
struct MixedRealityInteractionMappingU5BU5D_t689ED6694F3B293DEDEA6D5371268D36DC67AACE;
struct MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
struct TouchU5BU5D_t242545870BFCA81F368CCF82E00F9E2A7FB523B3;
struct UnityTouchControllerU5BU5D_t21C5ADD15D54D5FECC73542ACD6D8B9AE0C6F7FA;
struct PointerConfigU5BU5D_tB0CE3BD4887D9B9BFC82FC1CA265B076BFD7B59F;
struct BaseController_t1635F01D9B5000C345FAF98BAEEA495E97C32274;
struct BaseInputDeviceManager_t1D055DB03D88FA053C00671FEA5040B944CC26BC;
struct BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4;
struct BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0;
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184;
struct GenericJoystickController_t973A6C1908E4F5C9D15B9448798CFF811C3B9A90;
struct IMixedRealityControllerVisualizer_t7B6B8F308ED8917976841E02F1525D6B7E478F7B;
struct IMixedRealityInputSource_t9926A91DEC380AA837347E82976F5A6A9F9226C2;
struct IMixedRealityInputSourceDefinition_tE7BF76E1A2D7019ADB64FA561FB5D5DC1965E835;
struct IMixedRealityInputSystem_t73D9E8D52E761DF1CC230411D0EFD51104FF68B2;
struct IMixedRealityPointer_t6B17FD29F171D88877AB2EF9C59FEBB65ED6E446;
struct IMixedRealityServiceRegistrar_t4B893B7CDAAC977211D826D02C8522ECA327D715;
struct MixedRealityInteractionMapping_t10DB776EEA5255542F8F4AF0DC0BC566AF0095E0;
struct SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37;
struct String_t;
struct UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013;
struct UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct XboxController_t48DD56471B2420C49C7E36D67E73D20D8ECC72B1;
struct XboxControllerDefinition_t25A5573F5D1F3D81A713BF6732C51AC6EEF53851;
struct CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD;

IL2CPP_EXTERN_C RuntimeClass* BaseInputDeviceManager_t1D055DB03D88FA053C00671FEA5040B944CC26BC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GenericJoystickController_t973A6C1908E4F5C9D15B9448798CFF811C3B9A90_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMixedRealityController_t8BF4741E7DBA358A1DB46E1DD9EF33C9CDEB8BFA_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMixedRealityEventSource_t9E9DFD08DEE578702833FF502590A1E0476E59E1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMixedRealityInputSource_t9926A91DEC380AA837347E82976F5A6A9F9226C2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMixedRealityInputSystem_t73D9E8D52E761DF1CC230411D0EFD51104FF68B2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMixedRealityPointer_t6B17FD29F171D88877AB2EF9C59FEBB65ED6E446_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IMixedRealityTouchPointer_tE0FE8957BA2D11207816961004C2CA8B81C2F5DF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* XboxControllerDefinition_t25A5573F5D1F3D81A713BF6732C51AC6EEF53851_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral0CEA6BCEC90EDEFF96BDF8B9DFA3B15F88F92618;
IL2CPP_EXTERN_C String_t* _stringLiteral240F44D464CCC3E12D4D7AFDEC32B325BE29C87E;
IL2CPP_EXTERN_C String_t* _stringLiteral4D899EE9A99EE6B79B8715C4A8A17FC7E4C28DF9;
IL2CPP_EXTERN_C String_t* _stringLiteral4F59A907CA0E469899F0A752CE8865A082A11FCD;
IL2CPP_EXTERN_C String_t* _stringLiteral5A01D588B9C69138B51D8C228C7E6DF943913B44;
IL2CPP_EXTERN_C String_t* _stringLiteral6563818E4ABB744DF1C941B94BBE294F70A47042;
IL2CPP_EXTERN_C String_t* _stringLiteral7C854BA33FD2DC8ECA4532462C6C3BEBD01C42F4;
IL2CPP_EXTERN_C String_t* _stringLiteral801EACC9B8E831EA7D1A22ACE229E2222275490E;
IL2CPP_EXTERN_C String_t* _stringLiteral8E719678A0C6088F0DAF18FCE81FA5FB5D8AD4B2;
IL2CPP_EXTERN_C String_t* _stringLiteralBF8B574011A5AA65C13AB5BA38E67624D92741B6;
IL2CPP_EXTERN_C String_t* _stringLiteralC527D8933A29287B8D3C1EEF0C895DD35760EE27;
IL2CPP_EXTERN_C String_t* _stringLiteralD1C4A80C90449117887C3EFE0E5C9259A8AB441C;
IL2CPP_EXTERN_C String_t* _stringLiteralD605EF663B0E805D20EA905924A5BAB1060B65CE;
IL2CPP_EXTERN_C String_t* _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
IL2CPP_EXTERN_C String_t* _stringLiteralE706F4FB75F94F6CF18BF52AD26A43FD03E6C270;
IL2CPP_EXTERN_C const RuntimeMethod* BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* BaseDataProvider_1_set_Registrar_mA370F1A7CB1E5689906DAC10776EC5F4821A3EFC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Add_mC288B078F91986E705727939A2EAE0B3A6B56623_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Clear_m449D6FB13E51E487FB450B24A07846D745E9F001_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_GetEnumerator_m2E8FC157538E93BBBDBDCC3ECFBCEB23B63C3D22_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Remove_m76399CAD6C393B8D39ABFC83E392C1047620E4C7_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m42C586A94890C3EF834AACAB282182ABA986632C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_m1A01CF7AAEACC56D097C973FB27BA1DE1ECA19D5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_Dispose_m3AE8AB64B31129A28D2FAB496E4CCBF22576E00C_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m21E1D723A4EA1A8A474BEB11090E58DA5DA00517_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_MoveNext_m58F01378ECC3DD6D19EAE44971AF84ABAF720CBC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_m6F159853C1A8DAA77838EAFF7F6FD59EF3CA5900_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Enumerator_get_Current_mD6F90CCD398A75E7350E649489014B3E2DEE2F45_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* HashSet_1_GetEnumerator_m7F521399752E6007B0B4EA60CB82D580C158A8B9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Add_m8E4044843BE3B33D0739844AB9ABDC6F372B222D_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_Clear_m397BF703CED31925F3BAA65555857486FFF74C5B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1__ctor_m392698326ECD6E3496A93B576216BFD8CFB72875_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Count_m5BE1E4EF76832AA0C626FCBE458B3EACBB8D01F1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* List_1_get_Item_m081F12A624E259002EB2425F60894D8419F6A040_RuntimeMethod_var;

struct IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4;
struct MixedRealityInteractionMappingU5BU5D_t689ED6694F3B293DEDEA6D5371268D36DC67AACE;
struct MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct TouchU5BU5D_t242545870BFCA81F368CCF82E00F9E2A7FB523B3;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	EntryU5BU5D_t661D7AB2C7445EFBB9C8EAD4DE4F9BA7A240B62F* ____entries;
	int32_t ____count;
	int32_t ____freeList;
	int32_t ____freeCount;
	int32_t ____version;
	RuntimeObject* ____comparer;
	KeyCollection_tE794D6DD1B21B8F7F22ED237E5E52CE02DC50C87* ____keys;
	ValueCollection_tB296124607AD0E5448E6B9010FCA8DCA56C330EA* ____values;
	RuntimeObject* ____syncRoot;
};
struct HashSet_1_tA6A38ACBB9B75A13510D4F82BD093B367BE4666E  : public RuntimeObject
{
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets;
	SlotU5BU5D_t5352D3708E20A120FCB9C071207F940FB2F2C004* ____slots;
	int32_t ____count;
	int32_t ____lastIndex;
	int32_t ____freeList;
	RuntimeObject* ____comparer;
	int32_t ____version;
	SerializationInfo_t3C47F63E24BEB9FCE2DC6309E027F238DC5C5E37* ____siInfo;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D  : public RuntimeObject
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647  : public RuntimeObject
{
	UnityTouchControllerU5BU5D_t21C5ADD15D54D5FECC73542ACD6D8B9AE0C6F7FA* ____items;
	int32_t ____size;
	int32_t ____version;
	RuntimeObject* ____syncRoot;
};
struct U3CPrivateImplementationDetailsU3E_t80B8093CDE06DB3F26AAE0743C16402220EE2E9E  : public RuntimeObject
{
};
struct BaseInputSourceDefinition_t3C7E26E809069FB4D48181384861DEC5E2EA36DB  : public RuntimeObject
{
	uint8_t ___U3CHandednessU3Ek__BackingField;
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
struct Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80 
{
	HashSet_1_tA6A38ACBB9B75A13510D4F82BD093B367BE4666E* ____set;
	int32_t ____index;
	int32_t ____version;
	RuntimeObject* ____current;
};
struct Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8 
{
	HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* ____set;
	int32_t ____index;
	int32_t ____version;
	RuntimeObject* ____current;
};
struct KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 
{
	int32_t ___key;
	RuntimeObject* ___value;
};
struct KeyValuePair_2_t0EBAF7326F68F908F9523652CE68FEEFA5DD9CC1 
{
	int32_t ___key;
	UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* ___value;
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
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct MixedRealityInputAction_tD3B6E9CE7F20EFC9D066C519FAB848679FC62486 
{
	uint32_t ___id;
	String_t* ___description;
	int32_t ___axisConstraint;
};
struct MixedRealityInputAction_tD3B6E9CE7F20EFC9D066C519FAB848679FC62486_marshaled_pinvoke
{
	uint32_t ___id;
	char* ___description;
	int32_t ___axisConstraint;
};
struct MixedRealityInputAction_tD3B6E9CE7F20EFC9D066C519FAB848679FC62486_marshaled_com
{
	uint32_t ___id;
	Il2CppChar* ___description;
	int32_t ___axisConstraint;
};
struct MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 
{
	int32_t ___U3CKeyCodeU3Ek__BackingField;
	String_t* ___U3CAxisCodeXU3Ek__BackingField;
	String_t* ___U3CAxisCodeYU3Ek__BackingField;
	bool ___U3CInvertXAxisU3Ek__BackingField;
	bool ___U3CInvertYAxisU3Ek__BackingField;
};
struct MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6_marshaled_pinvoke
{
	int32_t ___U3CKeyCodeU3Ek__BackingField;
	char* ___U3CAxisCodeXU3Ek__BackingField;
	char* ___U3CAxisCodeYU3Ek__BackingField;
	int32_t ___U3CInvertXAxisU3Ek__BackingField;
	int32_t ___U3CInvertYAxisU3Ek__BackingField;
};
struct MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6_marshaled_com
{
	int32_t ___U3CKeyCodeU3Ek__BackingField;
	Il2CppChar* ___U3CAxisCodeXU3Ek__BackingField;
	Il2CppChar* ___U3CAxisCodeYU3Ek__BackingField;
	int32_t ___U3CInvertXAxisU3Ek__BackingField;
	int32_t ___U3CInvertYAxisU3Ek__BackingField;
};
struct Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 
{
	float ___x;
	float ___y;
	float ___z;
	float ___w;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct UInt16_tF4C148C876015C212FD72652D0B6ED8CC247A455 
{
	uint16_t ___m_value;
};
struct UInt32_t1833D51FFA667B18A5AA4B8D34DE284F8495D29B 
{
	uint32_t ___m_value;
};
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 
{
	float ___x;
	float ___y;
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
struct XboxControllerDefinition_t25A5573F5D1F3D81A713BF6732C51AC6EEF53851  : public BaseInputSourceDefinition_t3C7E26E809069FB4D48181384861DEC5E2EA36DB
{
};
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D100_t942D7E36E3FA5FC5202F32A1D1B5FCDB7A5C5432 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D100_t942D7E36E3FA5FC5202F32A1D1B5FCDB7A5C5432__padding[100];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D116_tB8D6B1A3F19DB7FAF303341740D31F6D119358D6 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D116_tB8D6B1A3F19DB7FAF303341740D31F6D119358D6__padding[116];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D128_t39EB4776048FC367F8813BC67040B19266478EF2 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D128_t39EB4776048FC367F8813BC67040B19266478EF2__padding[128];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D200_t4DB3C08538D1CACC4E58C94DC42C4D01356387B4 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D200_t4DB3C08538D1CACC4E58C94DC42C4D01356387B4__padding[200];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D2048_t2713C6E235D67364D35C73D0BD3250A5A81799B2 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D2048_t2713C6E235D67364D35C73D0BD3250A5A81799B2__padding[2048];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D26581_tFE5516EB71B6FE17A1D51605442B6BD6C458C9A3 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D26581_tFE5516EB71B6FE17A1D51605442B6BD6C458C9A3__padding[26581];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D36_t883D0DA32324FB23DF3CD299F613C1988522BE7B 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D36_t883D0DA32324FB23DF3CD299F613C1988522BE7B__padding[36];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D40_t09764879D221D2A724414C49B27F48BC74E9F563 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D40_t09764879D221D2A724414C49B27F48BC74E9F563__padding[40];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D4480_t719907177F9DBBD17FB37A5665323D9060A32805 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D4480_t719907177F9DBBD17FB37A5665323D9060A32805__padding[4480];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D48_tB35C554000A7A46339DFA53481EB76E8C344EFF5 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D48_tB35C554000A7A46339DFA53481EB76E8C344EFF5__padding[48];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D5120_tC8C1FF40A6ADC5913171945BD0B45FB66ACED933 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D5120_tC8C1FF40A6ADC5913171945BD0B45FB66ACED933__padding[5120];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D52133_t153C3A5ABAE08AF15CAF6DC80CC4DC1CD009F037 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D52133_t153C3A5ABAE08AF15CAF6DC80CC4DC1CD009F037__padding[52133];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D576_t065555E741C68D0F6AD0E15B9426919B313225E0 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D576_t065555E741C68D0F6AD0E15B9426919B313225E0__padding[576];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D64_t9F1EBEB9F3039A04B3E0D29893691543BE27013A 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D64_t9F1EBEB9F3039A04B3E0D29893691543BE27013A__padding[64];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D864_t9E3A0540A0D84BF9FE806A7913CE98584E8C926F 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D864_t9E3A0540A0D84BF9FE806A7913CE98584E8C926F__padding[864];
	};
};
#pragma pack(pop, tp)
#pragma pack(push, tp, 1)
struct __StaticArrayInitTypeSizeU3D96_tC5AB142BC856350C8BED251B674527CF1976CBEF 
{
	union
	{
		struct
		{
			union
			{
			};
		};
		uint8_t __StaticArrayInitTypeSizeU3D96_tC5AB142BC856350C8BED251B674527CF1976CBEF__padding[96];
	};
};
#pragma pack(pop, tp)
struct Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3 
{
	Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* ____dictionary;
	int32_t ____version;
	int32_t ____index;
	KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 ____current;
	int32_t ____getEnumeratorRetType;
};
struct Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA 
{
	Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* ____dictionary;
	int32_t ____version;
	int32_t ____index;
	KeyValuePair_2_t0EBAF7326F68F908F9523652CE68FEEFA5DD9CC1 ____current;
	int32_t ____getEnumeratorRetType;
};
struct BaseController_t1635F01D9B5000C345FAF98BAEEA495E97C32274  : public RuntimeObject
{
	RuntimeObject* ___U3CDefinitionU3Ek__BackingField;
	bool ___U3CEnabledU3Ek__BackingField;
	int32_t ___U3CTrackingStateU3Ek__BackingField;
	uint8_t ___U3CControllerHandednessU3Ek__BackingField;
	RuntimeObject* ___U3CInputSourceU3Ek__BackingField;
	RuntimeObject* ___U3CVisualizerU3Ek__BackingField;
	bool ___U3CIsPositionAvailableU3Ek__BackingField;
	bool ___U3CIsPositionApproximateU3Ek__BackingField;
	bool ___U3CIsRotationAvailableU3Ek__BackingField;
	MixedRealityInteractionMappingU5BU5D_t689ED6694F3B293DEDEA6D5371268D36DC67AACE* ___U3CInteractionsU3Ek__BackingField;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___U3CAngularVelocityU3Ek__BackingField;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___U3CVelocityU3Ek__BackingField;
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
struct MixedRealityPose_tE60115C271AC50B8C11BA3B404BFCA99C7B2EFF5 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___position;
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___rotation;
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
struct Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Origin;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Direction;
};
struct Touch_t03E51455ED508492B3F278903A0114FA0E87B417 
{
	int32_t ___m_FingerId;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_Position;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_RawPosition;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_PositionDelta;
	float ___m_TimeDelta;
	int32_t ___m_TapCount;
	int32_t ___m_Phase;
	int32_t ___m_Type;
	float ___m_Pressure;
	float ___m_maximumPossiblePressure;
	float ___m_Radius;
	float ___m_RadiusVariance;
	float ___m_AltitudeAngle;
	float ___m_AzimuthAngle;
};
struct AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 
{
	intptr_t ___m_Ptr;
};
struct BaseDataProvider_1_t1C7B9F1707FEB27659F53B230E0A18282D2F7F20  : public BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0
{
	RuntimeObject* ___U3CRegistrarU3Ek__BackingField;
	RuntimeObject* ___U3CServiceU3Ek__BackingField;
};
struct BaseDataProvider_1_t8DC280A360428C68343AA5D6B95788F4A050196F  : public BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0
{
	RuntimeObject* ___U3CRegistrarU3Ek__BackingField;
	RuntimeObject* ___U3CServiceU3Ek__BackingField;
};
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
struct GenericJoystickController_t973A6C1908E4F5C9D15B9448798CFF811C3B9A90  : public BaseController_t1635F01D9B5000C345FAF98BAEEA495E97C32274
{
	float ___U3CPointerOffsetAngleU3Ek__BackingField;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___dualAxisPosition;
	MixedRealityPose_tE60115C271AC50B8C11BA3B404BFCA99C7B2EFF5 ___pointerOffsetPose;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___CurrentControllerPosition;
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___CurrentControllerRotation;
	MixedRealityPose_tE60115C271AC50B8C11BA3B404BFCA99C7B2EFF5 ___LastControllerPose;
	MixedRealityPose_tE60115C271AC50B8C11BA3B404BFCA99C7B2EFF5 ___CurrentControllerPose;
	MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* ___U3CLegacyInputSupportU3Ek__BackingField;
	MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* ___U3CLeftHandedLegacyInputSupportU3Ek__BackingField;
	MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* ___U3CRightHandedLegacyInputSupportU3Ek__BackingField;
};
struct MixedRealityInteractionMapping_t10DB776EEA5255542F8F4AF0DC0BC566AF0095E0  : public RuntimeObject
{
	uint32_t ___id;
	String_t* ___description;
	int32_t ___axisType;
	int32_t ___inputType;
	MixedRealityInputAction_tD3B6E9CE7F20EFC9D066C519FAB848679FC62486 ___inputAction;
	int32_t ___keyCode;
	String_t* ___axisCodeX;
	String_t* ___axisCodeY;
	bool ___invertXAxis;
	bool ___invertYAxis;
	bool ___changed;
	RuntimeObject* ___rawData;
	bool ___boolData;
	float ___floatData;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___vector2Data;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___positionData;
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___rotationData;
	MixedRealityPose_tE60115C271AC50B8C11BA3B404BFCA99C7B2EFF5 ___poseData;
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
struct UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013  : public BaseController_t1635F01D9B5000C345FAF98BAEEA495E97C32274
{
	float ___U3CMaxTapContactTimeU3Ek__BackingField;
	float ___U3CManipulationThresholdU3Ek__BackingField;
	Touch_t03E51455ED508492B3F278903A0114FA0E87B417 ___U3CTouchDataU3Ek__BackingField;
	Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___U3CScreenPointRayU3Ek__BackingField;
	float ___U3CLifetimeU3Ek__BackingField;
	bool ___isTouched;
	MixedRealityInputAction_tD3B6E9CE7F20EFC9D066C519FAB848679FC62486 ___holdingAction;
	bool ___isHolding;
	MixedRealityInputAction_tD3B6E9CE7F20EFC9D066C519FAB848679FC62486 ___manipulationAction;
	bool ___isManipulating;
	MixedRealityPose_tE60115C271AC50B8C11BA3B404BFCA99C7B2EFF5 ___lastPose;
	bool ___isNewController;
};
struct BaseInputDeviceManager_t1D055DB03D88FA053C00671FEA5040B944CC26BC  : public BaseDataProvider_1_t1C7B9F1707FEB27659F53B230E0A18282D2F7F20
{
	bool ___enablePointerCache;
	PointerConfigU5BU5D_tB0CE3BD4887D9B9BFC82FC1CA265B076BFD7B59F* ___pointerConfigurations;
	Dictionary_2_t924EC80B88AF529C31B6BD658C27711A7B2B2A5E* ___activePointersToConfig;
};
struct BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	bool ___isCustomProfile;
};
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};
struct XboxController_t48DD56471B2420C49C7E36D67E73D20D8ECC72B1  : public GenericJoystickController_t973A6C1908E4F5C9D15B9448798CFF811C3B9A90
{
	MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* ___U3CLegacyInputSupportU3Ek__BackingField;
};
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};
struct UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925  : public BaseInputDeviceManager_t1D055DB03D88FA053C00671FEA5040B944CC26BC
{
	List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* ___touchesToRemove;
};
struct List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D_StaticFields
{
	ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___s_emptyArray;
};
struct List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647_StaticFields
{
	UnityTouchControllerU5BU5D_t21C5ADD15D54D5FECC73542ACD6D8B9AE0C6F7FA* ___s_emptyArray;
};
struct U3CPrivateImplementationDetailsU3E_t80B8093CDE06DB3F26AAE0743C16402220EE2E9E_StaticFields
{
	__StaticArrayInitTypeSizeU3D5120_tC8C1FF40A6ADC5913171945BD0B45FB66ACED933 ___166ED64AD55DA1373758C8365D71D3115CFA2C21A6904B055D68F4E7CBE12122;
	__StaticArrayInitTypeSizeU3D128_t39EB4776048FC367F8813BC67040B19266478EF2 ___19431BCEA58601E38F5D80999B735D529CA7EC294A8A3CC463E90E8BBBFB7199;
	__StaticArrayInitTypeSizeU3D64_t9F1EBEB9F3039A04B3E0D29893691543BE27013A ___1A7C8DC3280280AAB4B04657941E2261F8BD452F79F430A07BD1B4C14BA58B93;
	__StaticArrayInitTypeSizeU3D96_tC5AB142BC856350C8BED251B674527CF1976CBEF ___312BC4C7256E0CB735D462954C5B8110B7D71835B0827B68B9BA013556A4EC48;
	__StaticArrayInitTypeSizeU3D576_t065555E741C68D0F6AD0E15B9426919B313225E0 ___31B73E648689B9DD93B0B426840C27135F65D125AEEC68D7D078ADEB6304D324;
	__StaticArrayInitTypeSizeU3D96_tC5AB142BC856350C8BED251B674527CF1976CBEF ___3981A8B4D7B4688FAE246263B44512D1738F5ED4B868734FA3A4C30AECAF57B2;
	__StaticArrayInitTypeSizeU3D200_t4DB3C08538D1CACC4E58C94DC42C4D01356387B4 ___414690C1EDD43034229489AB29A3D8E2D41AE89F59F905D0BB52A3E125774EAA;
	__StaticArrayInitTypeSizeU3D36_t883D0DA32324FB23DF3CD299F613C1988522BE7B ___4C7E2B6EF6530C5F9B191FEEAF9D0EE86308E7EC2C3691CA0F528B8A4BB26510;
	__StaticArrayInitTypeSizeU3D26581_tFE5516EB71B6FE17A1D51605442B6BD6C458C9A3 ___4FD22FA8A8F357582F32BA0B9ACE3DFF0E18579247F08B3674DB0622DDCD0D9B;
	__StaticArrayInitTypeSizeU3D96_tC5AB142BC856350C8BED251B674527CF1976CBEF ___577BB66DB352A52651963484243DD20947F8819D4C6589BA449C17677806F41B;
	__StaticArrayInitTypeSizeU3D864_t9E3A0540A0D84BF9FE806A7913CE98584E8C926F ___60B965BB65E9656B7C430E76BFD1B84A57AA38A0D55D973D942479D398FA4B61;
	__StaticArrayInitTypeSizeU3D40_t09764879D221D2A724414C49B27F48BC74E9F563 ___6BE2711CE0EEE34B5775EC04919652D5C220834E0553C3CE9D9202604E9B5A3A;
	__StaticArrayInitTypeSizeU3D4480_t719907177F9DBBD17FB37A5665323D9060A32805 ___74B0FE229390D9CCB2FB31CA5E2117E1C1CC74BBA9CB5E9C81EBEEF5DBA28B6C;
	__StaticArrayInitTypeSizeU3D96_tC5AB142BC856350C8BED251B674527CF1976CBEF ___7815BB712A6D8F7E2BFE959EC3578A069089E0C5B5A63CCDFAA953980B215B3E;
	__StaticArrayInitTypeSizeU3D2048_t2713C6E235D67364D35C73D0BD3250A5A81799B2 ___903088B3ED84F3BC399E07866758BC1B0D48B07E259D87A04F62053B060DA9CD;
	__StaticArrayInitTypeSizeU3D100_t942D7E36E3FA5FC5202F32A1D1B5FCDB7A5C5432 ___94B32A0DD54D0AA9D39E3C1A06690550136C23DA388E8F92B1FB04644A854E0C;
	__StaticArrayInitTypeSizeU3D116_tB8D6B1A3F19DB7FAF303341740D31F6D119358D6 ___94C001844276A4E0B417054115A72DA8D74AFE9AADF53691F8C4C7D2CC6010A9;
	__StaticArrayInitTypeSizeU3D100_t942D7E36E3FA5FC5202F32A1D1B5FCDB7A5C5432 ___A0F2B0EA91FC933B70E6B34E8A86F82FFB029DE52E4E48B264F08511F3196BEF;
	__StaticArrayInitTypeSizeU3D36_t883D0DA32324FB23DF3CD299F613C1988522BE7B ___B94D26CC74B3661C2F35A8D65F830F186E288414B1D13F5C0D78A6F6FDF0D88C;
	__StaticArrayInitTypeSizeU3D52133_t153C3A5ABAE08AF15CAF6DC80CC4DC1CD009F037 ___C48D24B97E9F21A915A4D9652399CD76794ED77B04ADB1F8F03F3BA95680602A;
	__StaticArrayInitTypeSizeU3D576_t065555E741C68D0F6AD0E15B9426919B313225E0 ___CAE6939691EE17FA45FEAE4A731F612ED2C6DCC7CD35D1F0BE9E486FD960C9C9;
	__StaticArrayInitTypeSizeU3D64_t9F1EBEB9F3039A04B3E0D29893691543BE27013A ___D10E3D59BD6AD5CB4BCB53B1A015C024866004634D836A94ABBBD127B2D2BF34;
	__StaticArrayInitTypeSizeU3D200_t4DB3C08538D1CACC4E58C94DC42C4D01356387B4 ___DFF88A40C6B25DC78B9940DEE88C8ACE92C192949231288E657194DE5C41591C;
	__StaticArrayInitTypeSizeU3D48_tB35C554000A7A46339DFA53481EB76E8C344EFF5 ___F7976EDBEC20C2EDD79E46C76B7ECF1F269D60662E7F3FC1D971A7434B9CABC8;
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
struct IntPtr_t_StaticFields
{
	intptr_t ___Zero;
};
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7_StaticFields
{
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___zeroVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___oneVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___upVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___downVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___leftVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___rightVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___positiveInfinityVector;
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___negativeInfinityVector;
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
struct GenericJoystickController_t973A6C1908E4F5C9D15B9448798CFF811C3B9A90_StaticFields
{
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdateControllerPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdateButtonDataPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdateSingleAxisDataPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdateDualAxisDataPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdatePoseDataPerfMarker;
};
struct UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013_StaticFields
{
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdatePerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___EndTouchPerfMarker;
};
struct BaseInputDeviceManager_t1D055DB03D88FA053C00671FEA5040B944CC26BC_StaticFields
{
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___RequestPointersPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___RecyclePointersPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___CreatePointerPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___CleanActivePointersPerfMarker;
};
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184_StaticFields
{
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPreCull;
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPreRender;
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPostRender;
};
struct UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields
{
	Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* ___ActiveTouches;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdatePerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___AddTouchControllerPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___UpdateTouchDataPerfMarker;
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD ___RemoveTouchControllerPerfMarker;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
struct TouchU5BU5D_t242545870BFCA81F368CCF82E00F9E2A7FB523B3  : public RuntimeArray
{
	ALIGN_FIELD (8) Touch_t03E51455ED508492B3F278903A0114FA0E87B417 m_Items[1];

	inline Touch_t03E51455ED508492B3F278903A0114FA0E87B417 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Touch_t03E51455ED508492B3F278903A0114FA0E87B417* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Touch_t03E51455ED508492B3F278903A0114FA0E87B417 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Touch_t03E51455ED508492B3F278903A0114FA0E87B417* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 value)
	{
		m_Items[index] = value;
	}
};
struct IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4  : public RuntimeArray
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
struct MixedRealityInteractionMappingU5BU5D_t689ED6694F3B293DEDEA6D5371268D36DC67AACE  : public RuntimeArray
{
	ALIGN_FIELD (8) MixedRealityInteractionMapping_t10DB776EEA5255542F8F4AF0DC0BC566AF0095E0* m_Items[1];

	inline MixedRealityInteractionMapping_t10DB776EEA5255542F8F4AF0DC0BC566AF0095E0* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline MixedRealityInteractionMapping_t10DB776EEA5255542F8F4AF0DC0BC566AF0095E0** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, MixedRealityInteractionMapping_t10DB776EEA5255542F8F4AF0DC0BC566AF0095E0* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline MixedRealityInteractionMapping_t10DB776EEA5255542F8F4AF0DC0BC566AF0095E0* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline MixedRealityInteractionMapping_t10DB776EEA5255542F8F4AF0DC0BC566AF0095E0** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, MixedRealityInteractionMapping_t10DB776EEA5255542F8F4AF0DC0BC566AF0095E0* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
struct MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF  : public RuntimeArray
{
	ALIGN_FIELD (8) MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 m_Items[1];

	inline MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CAxisCodeXU3Ek__BackingField), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CAxisCodeYU3Ek__BackingField), (void*)NULL);
		#endif
	}
	inline MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CAxisCodeXU3Ek__BackingField), (void*)NULL);
		#if IL2CPP_ENABLE_STRICT_WRITE_BARRIERS
		Il2CppCodeGenWriteBarrier((void**)&((m_Items + index)->___U3CAxisCodeYU3Ek__BackingField), (void*)NULL);
		#endif
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


IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BaseDataProvider_1_set_Registrar_m1A130D1847D364BF3D65E45B6C85965B0637465F_gshared_inline (BaseDataProvider_1_t8DC280A360428C68343AA5D6B95788F4A050196F* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* List_1_get_Item_m33561245D64798C2AB07584C0EC4F240E4839A38_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, int32_t ___0_index, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* BaseDataProvider_1_get_Service_m9D57380441608DEC9ABF2199EA5585FC967E038F_gshared_inline (BaseDataProvider_1_t8DC280A360428C68343AA5D6B95788F4A050196F* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3 Dictionary_2_GetEnumerator_m3F1620145BA0815B7C7CD648EF054558AA26556A_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mAECCBE12C0427D7ACF88F82FA266F1AE37402565_gshared (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 Enumerator_get_Current_m90160D324DA0D9F5624A345F47D8E226A118911A_gshared_inline (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* KeyValuePair_2_get_Value_m8508BCECB0654E2E93B1A141382E2688ADE7EE7C_gshared_inline (KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8 HashSet_1_GetEnumerator_m143B98FEED7E9CABA2C494AB2F04DAD60A504635_gshared (HashSet_1_t2F33BEB06EEA4A872E2FAF464382422AA39AE885* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Enumerator_Dispose_mFB582AEAA2E73F3128B5571197BEDE256A83F657_gshared (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m139A176CD271A0532D75BE08DA7831C8C45CE28F_gshared_inline (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m27565F5ACCCC75C3DD34CC4CAE3E6AEFEB9144A6_gshared (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Enumerator_MoveNext_m4DC143BC57F14EDD85AB13B6D6F3B5D0E319B30E_gshared (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Clear_mE1EFF7C68491EE07D21EE9924475A559BF0A4773_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_m7316301B8CF47FB538886B229B2749EC160B9D5C_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_Add_mAF1EF7DA16BD70E252EA5C4B0F74DE519A02CBCD_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m12BAB2F82E34CAA21A7245AB61E48F106340C1A4_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, int32_t ___0_key, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m92E9AB321FBD7147CA109C822D99C8B0610C27B7_gshared (Dictionary_2_tA75D1125AC9BE8F005BA9B868B373398E643C907* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_NO_INLINE IL2CPP_METHOD_ATTR void List_1_AddWithResize_m79A9BF770BEF9C06BE40D5401E55E375F2726CC4_gshared (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, RuntimeObject* ___0_item, const RuntimeMethod* method) ;

IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager__ctor_mF8971528F66128300D34442CFE3562B18CE2268B (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, RuntimeObject* ___0_inputSystem, String_t* ___1_name, uint32_t ___2_priority, BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* ___3_profile, const RuntimeMethod* method) ;
inline void BaseDataProvider_1_set_Registrar_mA370F1A7CB1E5689906DAC10776EC5F4821A3EFC_inline (BaseDataProvider_1_t1C7B9F1707FEB27659F53B230E0A18282D2F7F20* __this, RuntimeObject* ___0_value, const RuntimeMethod* method)
{
	((  void (*) (BaseDataProvider_1_t1C7B9F1707FEB27659F53B230E0A18282D2F7F20*, RuntimeObject*, const RuntimeMethod*))BaseDataProvider_1_set_Registrar_m1A130D1847D364BF3D65E45B6C85965B0637465F_gshared_inline)(__this, ___0_value, method);
}
inline void List_1__ctor_m392698326ECD6E3496A93B576216BFD8CFB72875 (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647*, const RuntimeMethod*))List_1__ctor_m7F078BB342729BDF11327FD89D7872265328F690_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseInputDeviceManager__ctor_m55B7F2B3368B9234F956C7D94273E8CA0DBC15EC (BaseInputDeviceManager_t1D055DB03D88FA053C00671FEA5040B944CC26BC* __this, RuntimeObject* ___0_inputSystem, String_t* ___1_name, uint32_t ___2_priority, BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* ___3_profile, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline (AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseService_Update_m07A22E1552ABDCD9AD86737D12D43DA27915370D (BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0* __this, const RuntimeMethod* method) ;
inline UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* List_1_get_Item_m081F12A624E259002EB2425F60894D8419F6A040 (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* __this, int32_t ___0_index, const RuntimeMethod* method)
{
	return ((  UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* (*) (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647*, int32_t, const RuntimeMethod*))List_1_get_Item_m33561245D64798C2AB07584C0EC4F240E4839A38_gshared)(__this, ___0_index, method);
}
inline RuntimeObject* BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_inline (BaseDataProvider_1_t1C7B9F1707FEB27659F53B230E0A18282D2F7F20* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (BaseDataProvider_1_t1C7B9F1707FEB27659F53B230E0A18282D2F7F20*, const RuntimeMethod*))BaseDataProvider_1_get_Service_m9D57380441608DEC9ABF2199EA5585FC967E038F_gshared_inline)(__this, method);
}
inline int32_t List_1_get_Count_m5BE1E4EF76832AA0C626FCBE458B3EACBB8D01F1_inline (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* __this, const RuntimeMethod* method)
{
	return ((  int32_t (*) (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647*, const RuntimeMethod*))List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline)(__this, method);
}
inline void List_1_Clear_m397BF703CED31925F3BAA65555857486FFF74C5B_inline (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* __this, const RuntimeMethod* method)
{
	((  void (*) (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647*, const RuntimeMethod*))List_1_Clear_m16C1F2C61FED5955F10EB36BC1CB2DF34B128994_gshared_inline)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Input_get_touchCount_m057388BFC67A0F4CA53764B1022867ED81D01E39 (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TouchU5BU5D_t242545870BFCA81F368CCF82E00F9E2A7FB523B3* Input_get_touches_m7CFDF6848F3EC3A8FE458436B2B8BD14B5C65CEF (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* CameraCache_get_Main_m08DDDB3EC260B690A997F10C0B85678322E20B6A (const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 Touch_get_position_m41B9EB0F3F3E1BE98CEB388253A9E31979CB964A (Touch_t03E51455ED508492B3F278903A0114FA0E87B417* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector2_op_Implicit_m6D9CABB2C791A192867D7A4559D132BE86DD3EB7_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_v, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 Camera_ScreenPointToRay_m2887B9A49880B7AB670C57D66B67D6A6689FE315 (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_pos, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Touch_get_phase_mB82409FB2BE1C32ABDBA6A72E52A099D28AB70B0 (Touch_t03E51455ED508492B3F278903A0114FA0E87B417* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager_AddTouchController_m248F213328FAFF68BA479D32443A8ACF3C47CFAD (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 ___0_touch, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___1_ray, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager_UpdateTouchData_m447C7570CA37EA1F574652A787B6535E22BEDA02 (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 ___0_touch, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___1_ray, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager_RemoveTouchController_m94178FFA1C9D9ACDE31C97D6771727BF62D0F3F8 (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 ___0_touch, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BaseService_Disable_m75AA61136BE79E0C8EA4B058D1506882A56683C4 (BaseService_tB7EC5C0F60DC5EE2DA122A608226D3887B6421D0* __this, const RuntimeMethod* method) ;
inline Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA Dictionary_2_GetEnumerator_m2E8FC157538E93BBBDBDCC3ECFBCEB23B63C3D22 (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA (*) (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659*, const RuntimeMethod*))Dictionary_2_GetEnumerator_m3F1620145BA0815B7C7CD648EF054558AA26556A_gshared)(__this, method);
}
inline void Enumerator_Dispose_m3AE8AB64B31129A28D2FAB496E4CCBF22576E00C (Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA*, const RuntimeMethod*))Enumerator_Dispose_mAECCBE12C0427D7ACF88F82FA266F1AE37402565_gshared)(__this, method);
}
inline KeyValuePair_2_t0EBAF7326F68F908F9523652CE68FEEFA5DD9CC1 Enumerator_get_Current_mD6F90CCD398A75E7350E649489014B3E2DEE2F45_inline (Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA* __this, const RuntimeMethod* method)
{
	return ((  KeyValuePair_2_t0EBAF7326F68F908F9523652CE68FEEFA5DD9CC1 (*) (Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA*, const RuntimeMethod*))Enumerator_get_Current_m90160D324DA0D9F5624A345F47D8E226A118911A_gshared_inline)(__this, method);
}
inline UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_inline (KeyValuePair_2_t0EBAF7326F68F908F9523652CE68FEEFA5DD9CC1* __this, const RuntimeMethod* method)
{
	return ((  UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* (*) (KeyValuePair_2_t0EBAF7326F68F908F9523652CE68FEEFA5DD9CC1*, const RuntimeMethod*))KeyValuePair_2_get_Value_m8508BCECB0654E2E93B1A141382E2688ADE7EE7C_gshared_inline)(__this, method);
}
inline Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80 HashSet_1_GetEnumerator_m7F521399752E6007B0B4EA60CB82D580C158A8B9 (HashSet_1_tA6A38ACBB9B75A13510D4F82BD093B367BE4666E* __this, const RuntimeMethod* method)
{
	return ((  Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80 (*) (HashSet_1_tA6A38ACBB9B75A13510D4F82BD093B367BE4666E*, const RuntimeMethod*))HashSet_1_GetEnumerator_m143B98FEED7E9CABA2C494AB2F04DAD60A504635_gshared)(__this, method);
}
inline void Enumerator_Dispose_m1A01CF7AAEACC56D097C973FB27BA1DE1ECA19D5 (Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80* __this, const RuntimeMethod* method)
{
	((  void (*) (Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80*, const RuntimeMethod*))Enumerator_Dispose_mFB582AEAA2E73F3128B5571197BEDE256A83F657_gshared)(__this, method);
}
inline RuntimeObject* Enumerator_get_Current_m6F159853C1A8DAA77838EAFF7F6FD59EF3CA5900_inline (Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80* __this, const RuntimeMethod* method)
{
	return ((  RuntimeObject* (*) (Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80*, const RuntimeMethod*))Enumerator_get_Current_m139A176CD271A0532D75BE08DA7831C8C45CE28F_gshared_inline)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* BaseController_get_InputSource_m8FE11DBDF7B41338ACF8AFF3A0C8FAD83E5D2870_inline (BaseController_t1635F01D9B5000C345FAF98BAEEA495E97C32274* __this, const RuntimeMethod* method) ;
inline bool Enumerator_MoveNext_m21E1D723A4EA1A8A474BEB11090E58DA5DA00517 (Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80*, const RuntimeMethod*))Enumerator_MoveNext_m27565F5ACCCC75C3DD34CC4CAE3E6AEFEB9144A6_gshared)(__this, method);
}
inline bool Enumerator_MoveNext_m58F01378ECC3DD6D19EAE44971AF84ABAF720CBC (Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA* __this, const RuntimeMethod* method)
{
	return ((  bool (*) (Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA*, const RuntimeMethod*))Enumerator_MoveNext_m4DC143BC57F14EDD85AB13B6D6F3B5D0E319B30E_gshared)(__this, method);
}
inline void Dictionary_2_Clear_m449D6FB13E51E487FB450B24A07846D745E9F001 (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659*, const RuntimeMethod*))Dictionary_2_Clear_mE1EFF7C68491EE07D21EE9924475A559BF0A4773_gshared)(__this, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Touch_get_fingerId_mC1DCE93BFA0574960A3AE5329AE6C5F7E06962BD (Touch_t03E51455ED508492B3F278903A0114FA0E87B417* __this, const RuntimeMethod* method) ;
inline bool Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443 (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* __this, int32_t ___0_key, UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659*, int32_t, UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013**, const RuntimeMethod*))Dictionary_2_TryGetValue_m7316301B8CF47FB538886B229B2749EC160B9D5C_gshared)(__this, ___0_key, ___1_value, method);
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8 (String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchController__ctor_m4B0EB0BFD5FEBEF6A2683D73222AF87586E6FF1C (UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* __this, int32_t ___0_trackingState, uint8_t ___1_controllerHandedness, RuntimeObject* ___2_inputSource, MixedRealityInteractionMappingU5BU5D_t689ED6694F3B293DEDEA6D5371268D36DC67AACE* ___3_interactions, const RuntimeMethod* method) ;
inline void Dictionary_2_Add_mC288B078F91986E705727939A2EAE0B3A6B56623 (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* __this, int32_t ___0_key, UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659*, int32_t, UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013*, const RuntimeMethod*))Dictionary_2_Add_mAF1EF7DA16BD70E252EA5C4B0F74DE519A02CBCD_gshared)(__this, ___0_key, ___1_value, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnityTouchController_set_TouchData_mB97FBCDCEAA19D2F64B19A6E2335E560A488DCDF_inline (UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* __this, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchController_StartTouch_m7B67940DB4A836A22DBA0BFCAB5C8E3718F6FDCB (UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnityTouchController_set_ScreenPointRay_mE43A0DFD4CBF95BEB09E939DDFFE6DEB55D11DE9_inline (UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* __this, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchController_Update_mA0FA63885F5493EB0BE0FFF70D7D5188059F9058 (UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchController_EndTouch_mF798FB64B48271C16D4E5FC6F2395C4467C0CFBF (UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* __this, const RuntimeMethod* method) ;
inline void List_1_Add_m8E4044843BE3B33D0739844AB9ABDC6F372B222D_inline (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* __this, UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* ___0_item, const RuntimeMethod* method)
{
	((  void (*) (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647*, UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013*, const RuntimeMethod*))List_1_Add_mEBCF994CC3814631017F46A387B1A192ED6C85C7_gshared_inline)(__this, ___0_item, method);
}
inline bool Dictionary_2_Remove_m76399CAD6C393B8D39ABFC83E392C1047620E4C7 (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* __this, int32_t ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659*, int32_t, const RuntimeMethod*))Dictionary_2_Remove_m12BAB2F82E34CAA21A7245AB61E48F106340C1A4_gshared)(__this, ___0_key, method);
}
inline void Dictionary_2__ctor_m42C586A94890C3EF834AACAB282182ABA986632C (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659*, const RuntimeMethod*))Dictionary_2__ctor_m92E9AB321FBD7147CA109C822D99C8B0610C27B7_gshared)(__this, method);
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline (ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD* __this, String_t* ___0_name, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2 (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6* __this, int32_t ___0_keyCode, String_t* ___1_axisCodeX, String_t* ___2_axisCodeY, bool ___3_invertXAxis, bool ___4_invertYAxis, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XboxControllerDefinition__ctor_mC350675EE8EA7005F1CBD3CE937BF9ABA932080F (XboxControllerDefinition_t25A5573F5D1F3D81A713BF6732C51AC6EEF53851* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GenericJoystickController__ctor_m2E8C5C397E6189E87DA99B5B36AFE12F91828BC5 (GenericJoystickController_t973A6C1908E4F5C9D15B9448798CFF811C3B9A90* __this, int32_t ___0_trackingState, uint8_t ___1_controllerHandedness, RuntimeObject* ___2_definition, RuntimeObject* ___3_inputSource, MixedRealityInteractionMappingU5BU5D_t689ED6694F3B293DEDEA6D5371268D36DC67AACE* ___4_interactions, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void AutoScope__ctor_m7F63A273E382CB6328736B6E7F321DDFA40EA9E3_inline (AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139* __this, intptr_t ___0_markerPtr, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IntPtr_op_Inequality_m90EFC9C4CAD9A33E309F2DDF98EE4E1DD253637B (intptr_t ___0_value1, intptr_t ___1_value2, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ProfilerUnsafeUtility_EndSample_mFDB4EFB160A9CB817D2F8ED21B88693616B27409 (intptr_t ___0_markerPtr, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR intptr_t ProfilerUnsafeUtility_CreateMarker_mC5E1AAB8CC1F0342065DF85BA3334445ED754E64 (String_t* ___0_name, uint16_t ___1_categoryId, uint16_t ___2_flags, int32_t ___3_metadataCount, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Array_Clear_m50BAA3751899858B097D3FF2ED31F284703FE5CB (RuntimeArray* ___0_array, int32_t ___1_index, int32_t ___2_length, const RuntimeMethod* method) ;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager__ctor_mEE9662C055797AFF477DB993616DF47B2AFFADE7 (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, RuntimeObject* ___0_registrar, RuntimeObject* ___1_inputSystem, String_t* ___2_name, uint32_t ___3_priority, BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* ___4_profile, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseDataProvider_1_set_Registrar_mA370F1A7CB1E5689906DAC10776EC5F4821A3EFC_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		RuntimeObject* L_0 = ___1_inputSystem;
		String_t* L_1 = ___2_name;
		uint32_t L_2 = ___3_priority;
		BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* L_3 = ___4_profile;
		UnityTouchDeviceManager__ctor_mF8971528F66128300D34442CFE3562B18CE2268B(__this, L_0, L_1, L_2, L_3, NULL);
		RuntimeObject* L_4 = ___0_registrar;
		BaseDataProvider_1_set_Registrar_mA370F1A7CB1E5689906DAC10776EC5F4821A3EFC_inline(__this, L_4, BaseDataProvider_1_set_Registrar_mA370F1A7CB1E5689906DAC10776EC5F4821A3EFC_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager__ctor_mF8971528F66128300D34442CFE3562B18CE2268B (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, RuntimeObject* ___0_inputSystem, String_t* ___1_name, uint32_t ___2_priority, BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* ___3_profile, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseInputDeviceManager_t1D055DB03D88FA053C00671FEA5040B944CC26BC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1__ctor_m392698326ECD6E3496A93B576216BFD8CFB72875_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* L_0 = (List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647*)il2cpp_codegen_object_new(List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647_il2cpp_TypeInfo_var);
		List_1__ctor_m392698326ECD6E3496A93B576216BFD8CFB72875(L_0, List_1__ctor_m392698326ECD6E3496A93B576216BFD8CFB72875_RuntimeMethod_var);
		__this->___touchesToRemove = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___touchesToRemove), (void*)L_0);
		RuntimeObject* L_1 = ___0_inputSystem;
		String_t* L_2 = ___1_name;
		uint32_t L_3 = ___2_priority;
		BaseMixedRealityProfile_tB4FDEF58FFD17796C0DB7241630B71CDF38FA1D4* L_4 = ___3_profile;
		il2cpp_codegen_runtime_class_init_inline(BaseInputDeviceManager_t1D055DB03D88FA053C00671FEA5040B944CC26BC_il2cpp_TypeInfo_var);
		BaseInputDeviceManager__ctor_m55B7F2B3368B9234F956C7D94273E8CA0DBC15EC(__this, L_1, L_2, L_3, L_4, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager_Update_m562521538D1EBF1AD4507E39E58AEE405C5C0E9F (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityController_t8BF4741E7DBA358A1DB46E1DD9EF33C9CDEB8BFA_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityInputSystem_t73D9E8D52E761DF1CC230411D0EFD51104FF68B2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Clear_m397BF703CED31925F3BAA65555857486FFF74C5B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Count_m5BE1E4EF76832AA0C626FCBE458B3EACBB8D01F1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_get_Item_m081F12A624E259002EB2425F60894D8419F6A040_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	RuntimeObject* V_4 = NULL;
	int32_t V_5 = 0;
	Touch_t03E51455ED508492B3F278903A0114FA0E87B417 V_6;
	memset((&V_6), 0, sizeof(V_6));
	Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 V_7;
	memset((&V_7), 0, sizeof(V_7));
	int32_t V_8 = 0;
	RuntimeObject* G_B6_0 = NULL;
	RuntimeObject* G_B5_0 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___UpdatePerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00ee:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			{
				bool L_2;
				L_2 = VirtualFuncInvoker0< bool >::Invoke(33, __this);
				if (L_2)
				{
					goto IL_001b_1;
				}
			}
			{
				goto IL_00fc;
			}

IL_001b_1:
			{
				BaseService_Update_m07A22E1552ABDCD9AD86737D12D43DA27915370D(__this, NULL);
				V_3 = 0;
				goto IL_0051_1;
			}

IL_0025_1:
			{
				List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* L_3 = __this->___touchesToRemove;
				int32_t L_4 = V_3;
				NullCheck(L_3);
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_5;
				L_5 = List_1_get_Item_m081F12A624E259002EB2425F60894D8419F6A040(L_3, L_4, List_1_get_Item_m081F12A624E259002EB2425F60894D8419F6A040_RuntimeMethod_var);
				V_4 = L_5;
				RuntimeObject* L_6;
				L_6 = BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_inline(__this, BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var);
				RuntimeObject* L_7 = L_6;
				if (L_7)
				{
					G_B6_0 = L_7;
					goto IL_003f_1;
				}
				G_B5_0 = L_7;
			}
			{
				goto IL_004d_1;
			}

IL_003f_1:
			{
				RuntimeObject* L_8 = V_4;
				NullCheck(L_8);
				RuntimeObject* L_9;
				L_9 = InterfaceFuncInvoker0< RuntimeObject* >::Invoke(4, IMixedRealityController_t8BF4741E7DBA358A1DB46E1DD9EF33C9CDEB8BFA_il2cpp_TypeInfo_var, L_8);
				RuntimeObject* L_10 = V_4;
				NullCheck(G_B6_0);
				InterfaceActionInvoker2< RuntimeObject*, RuntimeObject* >::Invoke(25, IMixedRealityInputSystem_t73D9E8D52E761DF1CC230411D0EFD51104FF68B2_il2cpp_TypeInfo_var, G_B6_0, L_9, L_10);
			}

IL_004d_1:
			{
				int32_t L_11 = V_3;
				V_3 = ((int32_t)il2cpp_codegen_add(L_11, 1));
			}

IL_0051_1:
			{
				int32_t L_12 = V_3;
				List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* L_13 = __this->___touchesToRemove;
				NullCheck(L_13);
				int32_t L_14;
				L_14 = List_1_get_Count_m5BE1E4EF76832AA0C626FCBE458B3EACBB8D01F1_inline(L_13, List_1_get_Count_m5BE1E4EF76832AA0C626FCBE458B3EACBB8D01F1_RuntimeMethod_var);
				if ((((int32_t)L_12) < ((int32_t)L_14)))
				{
					goto IL_0025_1;
				}
			}
			{
				List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* L_15 = __this->___touchesToRemove;
				NullCheck(L_15);
				List_1_Clear_m397BF703CED31925F3BAA65555857486FFF74C5B_inline(L_15, List_1_Clear_m397BF703CED31925F3BAA65555857486FFF74C5B_RuntimeMethod_var);
				int32_t L_16;
				L_16 = Input_get_touchCount_m057388BFC67A0F4CA53764B1022867ED81D01E39(NULL);
				V_2 = L_16;
				V_5 = 0;
				goto IL_00e7_1;
			}

IL_0075_1:
			{
				TouchU5BU5D_t242545870BFCA81F368CCF82E00F9E2A7FB523B3* L_17;
				L_17 = Input_get_touches_m7CFDF6848F3EC3A8FE458436B2B8BD14B5C65CEF(NULL);
				int32_t L_18 = V_5;
				NullCheck(L_17);
				int32_t L_19 = L_18;
				Touch_t03E51455ED508492B3F278903A0114FA0E87B417 L_20 = (L_17)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
				V_6 = L_20;
				Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_21;
				L_21 = CameraCache_get_Main_m08DDDB3EC260B690A997F10C0B85678322E20B6A(NULL);
				Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_22;
				L_22 = Touch_get_position_m41B9EB0F3F3E1BE98CEB388253A9E31979CB964A((&V_6), NULL);
				Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_23;
				L_23 = Vector2_op_Implicit_m6D9CABB2C791A192867D7A4559D132BE86DD3EB7_inline(L_22, NULL);
				NullCheck(L_21);
				Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_24;
				L_24 = Camera_ScreenPointToRay_m2887B9A49880B7AB670C57D66B67D6A6689FE315(L_21, L_23, NULL);
				V_7 = L_24;
				int32_t L_25;
				L_25 = Touch_get_phase_mB82409FB2BE1C32ABDBA6A72E52A099D28AB70B0((&V_6), NULL);
				V_8 = L_25;
				int32_t L_26 = V_8;
				switch (L_26)
				{
					case 0:
					{
						goto IL_00c1_1;
					}
					case 1:
					{
						goto IL_00cd_1;
					}
					case 2:
					{
						goto IL_00cd_1;
					}
					case 3:
					{
						goto IL_00d9_1;
					}
					case 4:
					{
						goto IL_00d9_1;
					}
				}
			}
			{
				goto IL_00e1_1;
			}

IL_00c1_1:
			{
				Touch_t03E51455ED508492B3F278903A0114FA0E87B417 L_27 = V_6;
				Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_28 = V_7;
				UnityTouchDeviceManager_AddTouchController_m248F213328FAFF68BA479D32443A8ACF3C47CFAD(__this, L_27, L_28, NULL);
				goto IL_00e1_1;
			}

IL_00cd_1:
			{
				Touch_t03E51455ED508492B3F278903A0114FA0E87B417 L_29 = V_6;
				Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_30 = V_7;
				UnityTouchDeviceManager_UpdateTouchData_m447C7570CA37EA1F574652A787B6535E22BEDA02(__this, L_29, L_30, NULL);
				goto IL_00e1_1;
			}

IL_00d9_1:
			{
				Touch_t03E51455ED508492B3F278903A0114FA0E87B417 L_31 = V_6;
				UnityTouchDeviceManager_RemoveTouchController_m94178FFA1C9D9ACDE31C97D6771727BF62D0F3F8(__this, L_31, NULL);
			}

IL_00e1_1:
			{
				int32_t L_32 = V_5;
				V_5 = ((int32_t)il2cpp_codegen_add(L_32, 1));
			}

IL_00e7_1:
			{
				int32_t L_33 = V_5;
				int32_t L_34 = V_2;
				if ((((int32_t)L_33) < ((int32_t)L_34)))
				{
					goto IL_0075_1;
				}
			}
			{
				goto IL_00fc;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00fc:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager_Disable_m9A2B2402C9C5C93BE7F978D01BE49751D65C2F2B (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Clear_m449D6FB13E51E487FB450B24A07846D745E9F001_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_GetEnumerator_m2E8FC157538E93BBBDBDCC3ECFBCEB23B63C3D22_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m1A01CF7AAEACC56D097C973FB27BA1DE1ECA19D5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_Dispose_m3AE8AB64B31129A28D2FAB496E4CCBF22576E00C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m21E1D723A4EA1A8A474BEB11090E58DA5DA00517_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_MoveNext_m58F01378ECC3DD6D19EAE44971AF84ABAF720CBC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_m6F159853C1A8DAA77838EAFF7F6FD59EF3CA5900_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Enumerator_get_Current_mD6F90CCD398A75E7350E649489014B3E2DEE2F45_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&HashSet_1_GetEnumerator_m7F521399752E6007B0B4EA60CB82D580C158A8B9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityEventSource_t9E9DFD08DEE578702833FF502590A1E0476E59E1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityInputSystem_t73D9E8D52E761DF1CC230411D0EFD51104FF68B2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA V_0;
	memset((&V_0), 0, sizeof(V_0));
	KeyValuePair_2_t0EBAF7326F68F908F9523652CE68FEEFA5DD9CC1 V_1;
	memset((&V_1), 0, sizeof(V_1));
	Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80 V_2;
	memset((&V_2), 0, sizeof(V_2));
	{
		BaseService_Disable_m75AA61136BE79E0C8EA4B058D1506882A56683C4(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* L_0 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___ActiveTouches;
		NullCheck(L_0);
		Enumerator_t177EAF41C12F2014CF3660F92330858544D2E0EA L_1;
		L_1 = Dictionary_2_GetEnumerator_m2E8FC157538E93BBBDBDCC3ECFBCEB23B63C3D22(L_0, Dictionary_2_GetEnumerator_m2E8FC157538E93BBBDBDCC3ECFBCEB23B63C3D22_RuntimeMethod_var);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00a6:
			{
				Enumerator_Dispose_m3AE8AB64B31129A28D2FAB496E4CCBF22576E00C((&V_0), Enumerator_Dispose_m3AE8AB64B31129A28D2FAB496E4CCBF22576E00C_RuntimeMethod_var);
				return;
			}
		});
		try
		{
			{
				goto IL_0098_1;
			}

IL_0016_1:
			{
				KeyValuePair_2_t0EBAF7326F68F908F9523652CE68FEEFA5DD9CC1 L_2;
				L_2 = Enumerator_get_Current_mD6F90CCD398A75E7350E649489014B3E2DEE2F45_inline((&V_0), Enumerator_get_Current_mD6F90CCD398A75E7350E649489014B3E2DEE2F45_RuntimeMethod_var);
				V_1 = L_2;
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_3;
				L_3 = KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_inline((&V_1), KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_RuntimeMethod_var);
				if (!L_3)
				{
					goto IL_0098_1;
				}
			}
			{
				RuntimeObject* L_4;
				L_4 = BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_inline(__this, BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var);
				if (!L_4)
				{
					goto IL_0098_1;
				}
			}
			{
				RuntimeObject* L_5;
				L_5 = BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_inline(__this, BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var);
				NullCheck(L_5);
				HashSet_1_tA6A38ACBB9B75A13510D4F82BD093B367BE4666E* L_6;
				L_6 = InterfaceFuncInvoker0< HashSet_1_tA6A38ACBB9B75A13510D4F82BD093B367BE4666E* >::Invoke(4, IMixedRealityInputSystem_t73D9E8D52E761DF1CC230411D0EFD51104FF68B2_il2cpp_TypeInfo_var, L_5);
				NullCheck(L_6);
				Enumerator_t863CF828B16CEE7D2D01E274F8E32DE140606E80 L_7;
				L_7 = HashSet_1_GetEnumerator_m7F521399752E6007B0B4EA60CB82D580C158A8B9(L_6, HashSet_1_GetEnumerator_m7F521399752E6007B0B4EA60CB82D580C158A8B9_RuntimeMethod_var);
				V_2 = L_7;
			}
			{
				auto __finallyBlock = il2cpp::utils::Finally([&]
				{

FINALLY_008a_1:
					{
						Enumerator_Dispose_m1A01CF7AAEACC56D097C973FB27BA1DE1ECA19D5((&V_2), Enumerator_Dispose_m1A01CF7AAEACC56D097C973FB27BA1DE1ECA19D5_RuntimeMethod_var);
						return;
					}
				});
				try
				{
					{
						goto IL_007f_2;
					}

IL_0042_2:
					{
						RuntimeObject* L_8;
						L_8 = Enumerator_get_Current_m6F159853C1A8DAA77838EAFF7F6FD59EF3CA5900_inline((&V_2), Enumerator_get_Current_m6F159853C1A8DAA77838EAFF7F6FD59EF3CA5900_RuntimeMethod_var);
						NullCheck(L_8);
						uint32_t L_9;
						L_9 = InterfaceFuncInvoker0< uint32_t >::Invoke(0, IMixedRealityEventSource_t9E9DFD08DEE578702833FF502590A1E0476E59E1_il2cpp_TypeInfo_var, L_8);
						UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_10;
						L_10 = KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_inline((&V_1), KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_RuntimeMethod_var);
						NullCheck(L_10);
						RuntimeObject* L_11;
						L_11 = BaseController_get_InputSource_m8FE11DBDF7B41338ACF8AFF3A0C8FAD83E5D2870_inline(L_10, NULL);
						NullCheck(L_11);
						uint32_t L_12;
						L_12 = InterfaceFuncInvoker0< uint32_t >::Invoke(0, IMixedRealityEventSource_t9E9DFD08DEE578702833FF502590A1E0476E59E1_il2cpp_TypeInfo_var, L_11);
						if ((!(((uint32_t)L_9) == ((uint32_t)L_12))))
						{
							goto IL_007f_2;
						}
					}
					{
						RuntimeObject* L_13;
						L_13 = BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_inline(__this, BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var);
						UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_14;
						L_14 = KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_inline((&V_1), KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_RuntimeMethod_var);
						NullCheck(L_14);
						RuntimeObject* L_15;
						L_15 = BaseController_get_InputSource_m8FE11DBDF7B41338ACF8AFF3A0C8FAD83E5D2870_inline(L_14, NULL);
						UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_16;
						L_16 = KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_inline((&V_1), KeyValuePair_2_get_Value_m082BAC2BE14CFA3CE8735241B7E2DE2294B6603A_RuntimeMethod_var);
						NullCheck(L_13);
						InterfaceActionInvoker2< RuntimeObject*, RuntimeObject* >::Invoke(25, IMixedRealityInputSystem_t73D9E8D52E761DF1CC230411D0EFD51104FF68B2_il2cpp_TypeInfo_var, L_13, L_15, L_16);
					}

IL_007f_2:
					{
						bool L_17;
						L_17 = Enumerator_MoveNext_m21E1D723A4EA1A8A474BEB11090E58DA5DA00517((&V_2), Enumerator_MoveNext_m21E1D723A4EA1A8A474BEB11090E58DA5DA00517_RuntimeMethod_var);
						if (L_17)
						{
							goto IL_0042_2;
						}
					}
					{
						goto IL_0098_1;
					}
				}
				catch(Il2CppExceptionWrapper& e)
				{
					__finallyBlock.StoreException(e.ex);
				}
			}

IL_0098_1:
			{
				bool L_18;
				L_18 = Enumerator_MoveNext_m58F01378ECC3DD6D19EAE44971AF84ABAF720CBC((&V_0), Enumerator_MoveNext_m58F01378ECC3DD6D19EAE44971AF84ABAF720CBC_RuntimeMethod_var);
				if (L_18)
				{
					goto IL_0016_1;
				}
			}
			{
				goto IL_00b4;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00b4:
	{
		il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* L_19 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___ActiveTouches;
		NullCheck(L_19);
		Dictionary_2_Clear_m449D6FB13E51E487FB450B24A07846D745E9F001(L_19, Dictionary_2_Clear_m449D6FB13E51E487FB450B24A07846D745E9F001_RuntimeMethod_var);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager_AddTouchController_m248F213328FAFF68BA479D32443A8ACF3C47CFAD (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 ___0_touch, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___1_ray, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Add_mC288B078F91986E705727939A2EAE0B3A6B56623_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityInputSource_t9926A91DEC380AA837347E82976F5A6A9F9226C2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityInputSystem_t73D9E8D52E761DF1CC230411D0EFD51104FF68B2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityPointer_t6B17FD29F171D88877AB2EF9C59FEBB65ED6E446_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityTouchPointer_tE0FE8957BA2D11207816961004C2CA8B81C2F5DF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5A01D588B9C69138B51D8C228C7E6DF943913B44);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* V_2 = NULL;
	RuntimeObject* V_3 = NULL;
	IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* V_4 = NULL;
	int32_t V_5 = 0;
	RuntimeObject* G_B11_0 = NULL;
	RuntimeObject* G_B10_0 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___AddTouchControllerPerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_00f0:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			{
				il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
				Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* L_2 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___ActiveTouches;
				int32_t L_3;
				L_3 = Touch_get_fingerId_mC1DCE93BFA0574960A3AE5329AE6C5F7E06962BD((&___0_touch), NULL);
				NullCheck(L_2);
				bool L_4;
				L_4 = Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443(L_2, L_3, (&V_2), Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443_RuntimeMethod_var);
				if (L_4)
				{
					goto IL_00c9_1;
				}
			}
			{
				V_3 = (RuntimeObject*)NULL;
				RuntimeObject* L_5;
				L_5 = BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_inline(__this, BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var);
				if (!L_5)
				{
					goto IL_0063_1;
				}
			}
			{
				IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* L_6;
				L_6 = VirtualFuncInvoker2< IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4*, int32_t, uint8_t >::Invoke(40, __this, ((int32_t)256), 7);
				V_4 = L_6;
				RuntimeObject* L_7;
				L_7 = BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_inline(__this, BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var);
				int32_t L_8;
				L_8 = Touch_get_fingerId_mC1DCE93BFA0574960A3AE5329AE6C5F7E06962BD((&___0_touch), NULL);
				int32_t L_9 = L_8;
				RuntimeObject* L_10 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_9);
				String_t* L_11;
				L_11 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteral5A01D588B9C69138B51D8C228C7E6DF943913B44, L_10, NULL);
				IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* L_12 = V_4;
				NullCheck(L_7);
				RuntimeObject* L_13;
				L_13 = InterfaceFuncInvoker3< RuntimeObject*, String_t*, IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4*, int32_t >::Invoke(22, IMixedRealityInputSystem_t73D9E8D52E761DF1CC230411D0EFD51104FF68B2_il2cpp_TypeInfo_var, L_7, L_11, L_12, 0);
				V_3 = L_13;
			}

IL_0063_1:
			{
				RuntimeObject* L_14 = V_3;
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_15 = (UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013*)il2cpp_codegen_object_new(UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013_il2cpp_TypeInfo_var);
				UnityTouchController__ctor_m4B0EB0BFD5FEBEF6A2683D73222AF87586E6FF1C(L_15, 0, 7, L_14, (MixedRealityInteractionMappingU5BU5D_t689ED6694F3B293DEDEA6D5371268D36DC67AACE*)NULL, NULL);
				V_2 = L_15;
				RuntimeObject* L_16 = V_3;
				if (!L_16)
				{
					goto IL_00b7_1;
				}
			}
			{
				V_5 = 0;
				goto IL_00ab_1;
			}

IL_0075_1:
			{
				RuntimeObject* L_17 = V_3;
				NullCheck(L_17);
				IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* L_18;
				L_18 = InterfaceFuncInvoker0< IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* >::Invoke(0, IMixedRealityInputSource_t9926A91DEC380AA837347E82976F5A6A9F9226C2_il2cpp_TypeInfo_var, L_17);
				int32_t L_19 = V_5;
				NullCheck(L_18);
				int32_t L_20 = L_19;
				RuntimeObject* L_21 = (L_18)->GetAt(static_cast<il2cpp_array_size_t>(L_20));
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_22 = V_2;
				NullCheck(L_21);
				InterfaceActionInvoker1< RuntimeObject* >::Invoke(1, IMixedRealityPointer_t6B17FD29F171D88877AB2EF9C59FEBB65ED6E446_il2cpp_TypeInfo_var, L_21, L_22);
				RuntimeObject* L_23 = V_3;
				NullCheck(L_23);
				IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* L_24;
				L_24 = InterfaceFuncInvoker0< IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* >::Invoke(0, IMixedRealityInputSource_t9926A91DEC380AA837347E82976F5A6A9F9226C2_il2cpp_TypeInfo_var, L_23);
				int32_t L_25 = V_5;
				NullCheck(L_24);
				int32_t L_26 = L_25;
				RuntimeObject* L_27 = (L_24)->GetAt(static_cast<il2cpp_array_size_t>(L_26));
				RuntimeObject* L_28 = ((RuntimeObject*)Castclass((RuntimeObject*)L_27, IMixedRealityTouchPointer_tE0FE8957BA2D11207816961004C2CA8B81C2F5DF_il2cpp_TypeInfo_var));
				Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_29 = ___1_ray;
				NullCheck(L_28);
				InterfaceActionInvoker1< Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 >::Invoke(3, IMixedRealityTouchPointer_tE0FE8957BA2D11207816961004C2CA8B81C2F5DF_il2cpp_TypeInfo_var, L_28, L_29);
				int32_t L_30;
				L_30 = Touch_get_fingerId_mC1DCE93BFA0574960A3AE5329AE6C5F7E06962BD((&___0_touch), NULL);
				NullCheck(L_28);
				InterfaceActionInvoker1< int32_t >::Invoke(1, IMixedRealityTouchPointer_tE0FE8957BA2D11207816961004C2CA8B81C2F5DF_il2cpp_TypeInfo_var, L_28, L_30);
				int32_t L_31 = V_5;
				V_5 = ((int32_t)il2cpp_codegen_add(L_31, 1));
			}

IL_00ab_1:
			{
				int32_t L_32 = V_5;
				RuntimeObject* L_33 = V_3;
				NullCheck(L_33);
				IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* L_34;
				L_34 = InterfaceFuncInvoker0< IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* >::Invoke(0, IMixedRealityInputSource_t9926A91DEC380AA837347E82976F5A6A9F9226C2_il2cpp_TypeInfo_var, L_33);
				NullCheck(L_34);
				if ((((int32_t)L_32) < ((int32_t)((int32_t)(((RuntimeArray*)L_34)->max_length)))))
				{
					goto IL_0075_1;
				}
			}

IL_00b7_1:
			{
				il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
				Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* L_35 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___ActiveTouches;
				int32_t L_36;
				L_36 = Touch_get_fingerId_mC1DCE93BFA0574960A3AE5329AE6C5F7E06962BD((&___0_touch), NULL);
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_37 = V_2;
				NullCheck(L_35);
				Dictionary_2_Add_mC288B078F91986E705727939A2EAE0B3A6B56623(L_35, L_36, L_37, Dictionary_2_Add_mC288B078F91986E705727939A2EAE0B3A6B56623_RuntimeMethod_var);
			}

IL_00c9_1:
			{
				RuntimeObject* L_38;
				L_38 = BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_inline(__this, BaseDataProvider_1_get_Service_m886AE537D966101848DD8F8D348F366C71253B3B_RuntimeMethod_var);
				RuntimeObject* L_39 = L_38;
				if (L_39)
				{
					G_B11_0 = L_39;
					goto IL_00d5_1;
				}
				G_B10_0 = L_39;
			}
			{
				goto IL_00e1_1;
			}

IL_00d5_1:
			{
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_40 = V_2;
				NullCheck(L_40);
				RuntimeObject* L_41;
				L_41 = BaseController_get_InputSource_m8FE11DBDF7B41338ACF8AFF3A0C8FAD83E5D2870_inline(L_40, NULL);
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_42 = V_2;
				NullCheck(G_B11_0);
				InterfaceActionInvoker2< RuntimeObject*, RuntimeObject* >::Invoke(24, IMixedRealityInputSystem_t73D9E8D52E761DF1CC230411D0EFD51104FF68B2_il2cpp_TypeInfo_var, G_B11_0, L_41, L_42);
			}

IL_00e1_1:
			{
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_43 = V_2;
				Touch_t03E51455ED508492B3F278903A0114FA0E87B417 L_44 = ___0_touch;
				NullCheck(L_43);
				UnityTouchController_set_TouchData_mB97FBCDCEAA19D2F64B19A6E2335E560A488DCDF_inline(L_43, L_44, NULL);
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_45 = V_2;
				NullCheck(L_45);
				UnityTouchController_StartTouch_m7B67940DB4A836A22DBA0BFCAB5C8E3718F6FDCB(L_45, NULL);
				goto IL_00fe;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_00fe:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager_UpdateTouchData_m447C7570CA37EA1F574652A787B6535E22BEDA02 (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 ___0_touch, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___1_ray, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityInputSource_t9926A91DEC380AA837347E82976F5A6A9F9226C2_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IMixedRealityTouchPointer_tE0FE8957BA2D11207816961004C2CA8B81C2F5DF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* V_2 = NULL;
	RuntimeObject* V_3 = NULL;
	Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 V_4;
	memset((&V_4), 0, sizeof(V_4));
	{
		il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___UpdateTouchDataPerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_0059:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			{
				il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
				Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* L_2 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___ActiveTouches;
				int32_t L_3;
				L_3 = Touch_get_fingerId_mC1DCE93BFA0574960A3AE5329AE6C5F7E06962BD((&___0_touch), NULL);
				NullCheck(L_2);
				bool L_4;
				L_4 = Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443(L_2, L_3, (&V_2), Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443_RuntimeMethod_var);
				if (L_4)
				{
					goto IL_0025_1;
				}
			}
			{
				goto IL_0067;
			}

IL_0025_1:
			{
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_5 = V_2;
				Touch_t03E51455ED508492B3F278903A0114FA0E87B417 L_6 = ___0_touch;
				NullCheck(L_5);
				UnityTouchController_set_TouchData_mB97FBCDCEAA19D2F64B19A6E2335E560A488DCDF_inline(L_5, L_6, NULL);
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_7 = V_2;
				NullCheck(L_7);
				RuntimeObject* L_8;
				L_8 = BaseController_get_InputSource_m8FE11DBDF7B41338ACF8AFF3A0C8FAD83E5D2870_inline(L_7, NULL);
				NullCheck(L_8);
				IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* L_9;
				L_9 = InterfaceFuncInvoker0< IMixedRealityPointerU5BU5D_t122E67DFE2F5B082397D95C08F6AA94DE36F86A4* >::Invoke(0, IMixedRealityInputSource_t9926A91DEC380AA837347E82976F5A6A9F9226C2_il2cpp_TypeInfo_var, L_8);
				NullCheck(L_9);
				int32_t L_10 = 0;
				RuntimeObject* L_11 = (L_9)->GetAt(static_cast<il2cpp_array_size_t>(L_10));
				V_3 = ((RuntimeObject*)Castclass((RuntimeObject*)L_11, IMixedRealityTouchPointer_tE0FE8957BA2D11207816961004C2CA8B81C2F5DF_il2cpp_TypeInfo_var));
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_12 = V_2;
				RuntimeObject* L_13 = V_3;
				Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_14 = ___1_ray;
				Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_15 = L_14;
				V_4 = L_15;
				NullCheck(L_13);
				InterfaceActionInvoker1< Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 >::Invoke(3, IMixedRealityTouchPointer_tE0FE8957BA2D11207816961004C2CA8B81C2F5DF_il2cpp_TypeInfo_var, L_13, L_15);
				Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_16 = V_4;
				NullCheck(L_12);
				UnityTouchController_set_ScreenPointRay_mE43A0DFD4CBF95BEB09E939DDFFE6DEB55D11DE9_inline(L_12, L_16, NULL);
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_17 = V_2;
				NullCheck(L_17);
				UnityTouchController_Update_mA0FA63885F5493EB0BE0FFF70D7D5188059F9058(L_17, NULL);
				goto IL_0067;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_0067:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager_RemoveTouchController_m94178FFA1C9D9ACDE31C97D6771727BF62D0F3F8 (UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925* __this, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 ___0_touch, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Remove_m76399CAD6C393B8D39ABFC83E392C1047620E4C7_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&List_1_Add_m8E4044843BE3B33D0739844AB9ABDC6F372B222D_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 V_0;
	memset((&V_0), 0, sizeof(V_0));
	ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD V_1;
	memset((&V_1), 0, sizeof(V_1));
	UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* V_2 = NULL;
	{
		il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_0 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___RemoveTouchControllerPerfMarker;
		V_1 = L_0;
		AutoScope_tFB983697E28885CB10FFDB92D7EFD0615AEF3139 L_1;
		L_1 = ProfilerMarker_Auto_m133FA724EB95D16187B37D2C8A501D7E989B1F8D_inline((&V_1), NULL);
		V_0 = L_1;
	}
	{
		auto __finallyBlock = il2cpp::utils::Finally([&]
		{

FINALLY_005e:
			{
				AutoScope_Dispose_mED763F3F51261EF8FB79DB32CD06E0A3F6C40481_inline((&V_0), NULL);
				return;
			}
		});
		try
		{
			{
				il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
				Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* L_2 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___ActiveTouches;
				int32_t L_3;
				L_3 = Touch_get_fingerId_mC1DCE93BFA0574960A3AE5329AE6C5F7E06962BD((&___0_touch), NULL);
				NullCheck(L_2);
				bool L_4;
				L_4 = Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443(L_2, L_3, (&V_2), Dictionary_2_TryGetValue_mD8FB0005B943D09AD2EC4FBA3CBD0CA49CCB7443_RuntimeMethod_var);
				if (L_4)
				{
					goto IL_0025_1;
				}
			}
			{
				goto IL_006c;
			}

IL_0025_1:
			{
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_5 = V_2;
				NullCheck(L_5);
				RuntimeObject* L_6;
				L_6 = BaseController_get_InputSource_m8FE11DBDF7B41338ACF8AFF3A0C8FAD83E5D2870_inline(L_5, NULL);
				VirtualActionInvoker1< RuntimeObject* >::Invoke(41, __this, L_6);
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_7 = V_2;
				Touch_t03E51455ED508492B3F278903A0114FA0E87B417 L_8 = ___0_touch;
				NullCheck(L_7);
				UnityTouchController_set_TouchData_mB97FBCDCEAA19D2F64B19A6E2335E560A488DCDF_inline(L_7, L_8, NULL);
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_9 = V_2;
				NullCheck(L_9);
				UnityTouchController_EndTouch_mF798FB64B48271C16D4E5FC6F2395C4467C0CFBF(L_9, NULL);
				List_1_t9CC4FEF58341CCE10DACB77CEBF836E20E4B3647* L_10 = __this->___touchesToRemove;
				UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* L_11 = V_2;
				NullCheck(L_10);
				List_1_Add_m8E4044843BE3B33D0739844AB9ABDC6F372B222D_inline(L_10, L_11, List_1_Add_m8E4044843BE3B33D0739844AB9ABDC6F372B222D_RuntimeMethod_var);
				il2cpp_codegen_runtime_class_init_inline(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
				Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* L_12 = ((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___ActiveTouches;
				int32_t L_13;
				L_13 = Touch_get_fingerId_mC1DCE93BFA0574960A3AE5329AE6C5F7E06962BD((&___0_touch), NULL);
				NullCheck(L_12);
				bool L_14;
				L_14 = Dictionary_2_Remove_m76399CAD6C393B8D39ABFC83E392C1047620E4C7(L_12, L_13, Dictionary_2_Remove_m76399CAD6C393B8D39ABFC83E392C1047620E4C7_RuntimeMethod_var);
				goto IL_006c;
			}
		}
		catch(Il2CppExceptionWrapper& e)
		{
			__finallyBlock.StoreException(e.ex);
		}
	}

IL_006c:
	{
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void UnityTouchDeviceManager__cctor_m92D1EF5E50EB250012FAD3165222CA9C4356775F (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m42C586A94890C3EF834AACAB282182ABA986632C_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4F59A907CA0E469899F0A752CE8865A082A11FCD);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBF8B574011A5AA65C13AB5BA38E67624D92741B6);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC527D8933A29287B8D3C1EEF0C895DD35760EE27);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE706F4FB75F94F6CF18BF52AD26A43FD03E6C270);
		s_Il2CppMethodInitialized = true;
	}
	{
		Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659* L_0 = (Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659*)il2cpp_codegen_object_new(Dictionary_2_t7CD1EB186E13B5D76F6E39D033C5A0CD1A2A5659_il2cpp_TypeInfo_var);
		Dictionary_2__ctor_m42C586A94890C3EF834AACAB282182ABA986632C(L_0, Dictionary_2__ctor_m42C586A94890C3EF834AACAB282182ABA986632C_RuntimeMethod_var);
		((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___ActiveTouches = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___ActiveTouches), (void*)L_0);
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_1;
		memset((&L_1), 0, sizeof(L_1));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_1), _stringLiteralBF8B574011A5AA65C13AB5BA38E67624D92741B6, NULL);
		((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___UpdatePerfMarker = L_1;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_2;
		memset((&L_2), 0, sizeof(L_2));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_2), _stringLiteral4F59A907CA0E469899F0A752CE8865A082A11FCD, NULL);
		((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___AddTouchControllerPerfMarker = L_2;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_3;
		memset((&L_3), 0, sizeof(L_3));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_3), _stringLiteralC527D8933A29287B8D3C1EEF0C895DD35760EE27, NULL);
		((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___UpdateTouchDataPerfMarker = L_3;
		ProfilerMarker_tA256E18DA86EDBC5528CE066FC91C96EE86501AD L_4;
		memset((&L_4), 0, sizeof(L_4));
		ProfilerMarker__ctor_mDD68B0A8B71E0301F592AF8891560150E55699C8_inline((&L_4), _stringLiteralE706F4FB75F94F6CF18BF52AD26A43FD03E6C270, NULL);
		((UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_StaticFields*)il2cpp_codegen_static_fields_for(UnityTouchDeviceManager_t862703BF437FF8A31556F69FBD68FF0248FBF925_il2cpp_TypeInfo_var))->___RemoveTouchControllerPerfMarker = L_4;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void XboxController__ctor_mE602583EB6A696AA2F65A90389610501779DC03F (XboxController_t48DD56471B2420C49C7E36D67E73D20D8ECC72B1* __this, int32_t ___0_trackingState, uint8_t ___1_controllerHandedness, RuntimeObject* ___2_inputSource, MixedRealityInteractionMappingU5BU5D_t689ED6694F3B293DEDEA6D5371268D36DC67AACE* ___3_interactions, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GenericJoystickController_t973A6C1908E4F5C9D15B9448798CFF811C3B9A90_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&XboxControllerDefinition_t25A5573F5D1F3D81A713BF6732C51AC6EEF53851_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0CEA6BCEC90EDEFF96BDF8B9DFA3B15F88F92618);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral240F44D464CCC3E12D4D7AFDEC32B325BE29C87E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4D899EE9A99EE6B79B8715C4A8A17FC7E4C28DF9);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6563818E4ABB744DF1C941B94BBE294F70A47042);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7C854BA33FD2DC8ECA4532462C6C3BEBD01C42F4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral801EACC9B8E831EA7D1A22ACE229E2222275490E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8E719678A0C6088F0DAF18FCE81FA5FB5D8AD4B2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD1C4A80C90449117887C3EFE0E5C9259A8AB441C);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD605EF663B0E805D20EA905924A5BAB1060B65CE);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	{
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_0 = (MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF*)(MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF*)SZArrayNew(MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF_il2cpp_TypeInfo_var, (uint32_t)((int32_t)16));
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_1 = L_0;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_2;
		memset((&L_2), 0, sizeof(L_2));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_2), 0, _stringLiteral4D899EE9A99EE6B79B8715C4A8A17FC7E4C28DF9, _stringLiteral6563818E4ABB744DF1C941B94BBE294F70A47042, (bool)0, (bool)1, NULL);
		NullCheck(L_1);
		(L_1)->SetAt(static_cast<il2cpp_array_size_t>(0), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_2);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_3 = L_1;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_4;
		memset((&L_4), 0, sizeof(L_4));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_4), ((int32_t)338), _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_3);
		(L_3)->SetAt(static_cast<il2cpp_array_size_t>(1), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_4);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_5 = L_3;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_6;
		memset((&L_6), 0, sizeof(L_6));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_6), 0, _stringLiteral801EACC9B8E831EA7D1A22ACE229E2222275490E, _stringLiteralD1C4A80C90449117887C3EFE0E5C9259A8AB441C, (bool)0, (bool)1, NULL);
		NullCheck(L_5);
		(L_5)->SetAt(static_cast<il2cpp_array_size_t>(2), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_6);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_7 = L_5;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_8;
		memset((&L_8), 0, sizeof(L_8));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_8), ((int32_t)339), _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_7);
		(L_7)->SetAt(static_cast<il2cpp_array_size_t>(3), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_8);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_9 = L_7;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_10;
		memset((&L_10), 0, sizeof(L_10));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_10), 0, _stringLiteral8E719678A0C6088F0DAF18FCE81FA5FB5D8AD4B2, _stringLiteralD605EF663B0E805D20EA905924A5BAB1060B65CE, (bool)0, (bool)1, NULL);
		NullCheck(L_9);
		(L_9)->SetAt(static_cast<il2cpp_array_size_t>(4), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_10);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_11 = L_9;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_12;
		memset((&L_12), 0, sizeof(L_12));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_12), 0, _stringLiteral7C854BA33FD2DC8ECA4532462C6C3BEBD01C42F4, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_11);
		(L_11)->SetAt(static_cast<il2cpp_array_size_t>(5), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_12);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_13 = L_11;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_14;
		memset((&L_14), 0, sizeof(L_14));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_14), 0, _stringLiteral0CEA6BCEC90EDEFF96BDF8B9DFA3B15F88F92618, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_13);
		(L_13)->SetAt(static_cast<il2cpp_array_size_t>(6), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_14);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_15 = L_13;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_16;
		memset((&L_16), 0, sizeof(L_16));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_16), 0, _stringLiteral240F44D464CCC3E12D4D7AFDEC32B325BE29C87E, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_15);
		(L_15)->SetAt(static_cast<il2cpp_array_size_t>(7), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_16);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_17 = L_15;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_18;
		memset((&L_18), 0, sizeof(L_18));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_18), ((int32_t)336), _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_17);
		(L_17)->SetAt(static_cast<il2cpp_array_size_t>(8), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_18);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_19 = L_17;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_20;
		memset((&L_20), 0, sizeof(L_20));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_20), ((int32_t)337), _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_19);
		(L_19)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)9)), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_20);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_21 = L_19;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_22;
		memset((&L_22), 0, sizeof(L_22));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_22), ((int32_t)334), _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_21);
		(L_21)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)10)), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_22);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_23 = L_21;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_24;
		memset((&L_24), 0, sizeof(L_24));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_24), ((int32_t)335), _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_23);
		(L_23)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)11)), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_24);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_25 = L_23;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_26;
		memset((&L_26), 0, sizeof(L_26));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_26), ((int32_t)330), _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_25);
		(L_25)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)12)), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_26);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_27 = L_25;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_28;
		memset((&L_28), 0, sizeof(L_28));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_28), ((int32_t)331), _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_27);
		(L_27)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)13)), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_28);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_29 = L_27;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_30;
		memset((&L_30), 0, sizeof(L_30));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_30), ((int32_t)332), _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_29);
		(L_29)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)14)), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_30);
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_31 = L_29;
		MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6 L_32;
		memset((&L_32), 0, sizeof(L_32));
		MixedRealityInteractionMappingLegacyInput__ctor_m36B9A37A6973FBDD469C5E1C526DE33DDA8DC2B2((&L_32), ((int32_t)333), _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, (bool)0, (bool)0, NULL);
		NullCheck(L_31);
		(L_31)->SetAt(static_cast<il2cpp_array_size_t>(((int32_t)15)), (MixedRealityInteractionMappingLegacyInput_tE9D2E40C94F2819FF0AEF36AC79AEA37EEC3E8C6)L_32);
		__this->___U3CLegacyInputSupportU3Ek__BackingField = L_31;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CLegacyInputSupportU3Ek__BackingField), (void*)L_31);
		int32_t L_33 = ___0_trackingState;
		uint8_t L_34 = ___1_controllerHandedness;
		XboxControllerDefinition_t25A5573F5D1F3D81A713BF6732C51AC6EEF53851* L_35 = (XboxControllerDefinition_t25A5573F5D1F3D81A713BF6732C51AC6EEF53851*)il2cpp_codegen_object_new(XboxControllerDefinition_t25A5573F5D1F3D81A713BF6732C51AC6EEF53851_il2cpp_TypeInfo_var);
		XboxControllerDefinition__ctor_mC350675EE8EA7005F1CBD3CE937BF9ABA932080F(L_35, NULL);
		RuntimeObject* L_36 = ___2_inputSource;
		MixedRealityInteractionMappingU5BU5D_t689ED6694F3B293DEDEA6D5371268D36DC67AACE* L_37 = ___3_interactions;
		il2cpp_codegen_runtime_class_init_inline(GenericJoystickController_t973A6C1908E4F5C9D15B9448798CFF811C3B9A90_il2cpp_TypeInfo_var);
		GenericJoystickController__ctor_m2E8C5C397E6189E87DA99B5B36AFE12F91828BC5(__this, L_33, L_34, L_35, L_36, L_37, NULL);
		return;
	}
}
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* XboxController_get_LegacyInputSupport_m54B6AE4213110760542085735A43946F147F1CB9 (XboxController_t48DD56471B2420C49C7E36D67E73D20D8ECC72B1* __this, const RuntimeMethod* method) 
{
	{
		MixedRealityInteractionMappingLegacyInputU5BU5D_tA5355B0D239C6D459111AC8A8D465B3200F4C3EF* L_0 = __this->___U3CLegacyInputSupportU3Ek__BackingField;
		return L_0;
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
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector2_op_Implicit_m6D9CABB2C791A192867D7A4559D132BE86DD3EB7_inline (Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___0_v, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_0 = ___0_v;
		float L_1 = L_0.___x;
		Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 L_2 = ___0_v;
		float L_3 = L_2.___y;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), L_1, L_3, (0.0f), NULL);
		V_0 = L_4;
		goto IL_001a;
	}

IL_001a:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5 = V_0;
		return L_5;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* BaseController_get_InputSource_m8FE11DBDF7B41338ACF8AFF3A0C8FAD83E5D2870_inline (BaseController_t1635F01D9B5000C345FAF98BAEEA495E97C32274* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CInputSourceU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnityTouchController_set_TouchData_mB97FBCDCEAA19D2F64B19A6E2335E560A488DCDF_inline (UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* __this, Touch_t03E51455ED508492B3F278903A0114FA0E87B417 ___0_value, const RuntimeMethod* method) 
{
	{
		Touch_t03E51455ED508492B3F278903A0114FA0E87B417 L_0 = ___0_value;
		__this->___U3CTouchDataU3Ek__BackingField = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void UnityTouchController_set_ScreenPointRay_mE43A0DFD4CBF95BEB09E939DDFFE6DEB55D11DE9_inline (UnityTouchController_tF7951C4CC3E70F902FE39943D0374EE4731BD013* __this, Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_value, const RuntimeMethod* method) 
{
	{
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_0 = ___0_value;
		__this->___U3CScreenPointRayU3Ek__BackingField = L_0;
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void BaseDataProvider_1_set_Registrar_m1A130D1847D364BF3D65E45B6C85965B0637465F_gshared_inline (BaseDataProvider_1_t8DC280A360428C68343AA5D6B95788F4A050196F* __this, RuntimeObject* ___0_value, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = ___0_value;
		__this->___U3CRegistrarU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CRegistrarU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* BaseDataProvider_1_get_Service_m9D57380441608DEC9ABF2199EA5585FC967E038F_gshared_inline (BaseDataProvider_1_t8DC280A360428C68343AA5D6B95788F4A050196F* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___U3CServiceU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t List_1_get_Count_m4407E4C389F22B8CEC282C15D56516658746C383_gshared_inline (List_1_tA239CB83DE5615F348BB0507E45F490F4F7C9A8D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____size;
		return L_0;
	}
}
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 Enumerator_get_Current_m90160D324DA0D9F5624A345F47D8E226A118911A_gshared_inline (Enumerator_tE92C1AC40A104A179B94F8A013728FD9314CFBD3* __this, const RuntimeMethod* method) 
{
	{
		KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3 L_0 = __this->____current;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* KeyValuePair_2_get_Value_m8508BCECB0654E2E93B1A141382E2688ADE7EE7C_gshared_inline (KeyValuePair_2_tDC26B09C26BA829DDE331BCB6AF7C508C763D7A3* __this, const RuntimeMethod* method) 
{
	{
		RuntimeObject* L_0 = __this->___value;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR RuntimeObject* Enumerator_get_Current_m139A176CD271A0532D75BE08DA7831C8C45CE28F_gshared_inline (Enumerator_t72556E98D7DDBE118A973D782D523D15A96461C8* __this, const RuntimeMethod* method) 
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
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) 
{
	{
		float L_0 = ___0_x;
		__this->___x = L_0;
		float L_1 = ___1_y;
		__this->___y = L_1;
		float L_2 = ___2_z;
		__this->___z = L_2;
		return;
	}
}
