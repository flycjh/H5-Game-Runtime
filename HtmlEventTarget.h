#pragma once

#include "HtmlElement.h"
#include <memory>
#include "OpenglFBO.h"
//��Ӧ�¼��Ļ���
class HtmlEventTarget:public HtmlElement
{
	DEFINE_CUSTOM_CLASS(HtmlEventTarget, HtmlElement)
public:
// 	struct EVENT_LISTENER_INFO
// 	{
// 		std::string szName;
// 		PersistentValue*value;
// 	};
// 	std::list<EVENT_LISTENER_INFO>m_eventList;//�¼�ִ��ʱ���ܻ�removeEventListener��ʹ��list���ܻ�������

// 	struct EVENT_WILL_EXEC//�첽ִ���¼���ÿ���¼�
// 	{
// 		HtmlEventTarget*pHtmlObj = nullptr;
// 		std::string szEventName;
// 	};
// 	static std::list<EVENT_WILL_EXEC>s_eventWillExec;//����
	



	BEGIN_CUSTOM_FUNCTION
		DEFINE_CUSTOM_FUNCTION("addEventListener", &HtmlEventTarget::addEventListener, 3)
		DEFINE_CUSTOM_FUNCTION("removeEventListener", &HtmlEventTarget::removeEventListener, 3)
		DEFINE_CUSTOM_FUNCTION("dispatchEvent", &HtmlEventTarget::dispatchEvent, 1)

		END_CUSTOM_FUNCTION

		BEGIN_CUSTOM_PROPERTY
		DEFINE_CUSTOM_PROPERTY("visibility")
		DEFINE_CUSTOM_PROPERTY("display")
		DEFINE_CUSTOM_PROPERTY("ontouchstart")
		DEFINE_CUSTOM_PROPERTY("ontouchmove")
		DEFINE_CUSTOM_PROPERTY("ontouchend")
		END_CUSTOM_PROPERTY




	bool m_bVisibility = true;
	bool m_bDisplay = true;






	HtmlEventTarget();
	virtual ~HtmlEventTarget();
	static bool InitClass(const HandleContext&context);

	virtual bool OnGetProperty(GetPropertyArgs&args) ;

	virtual bool OnSetProperty(SetPropertyArgs&args) ;

	virtual void OnFinalize(FinalizeArgs&args) ;

	virtual bool OnConstructor(IFunctionCallbackArgs&args) ;

	bool addEventListener(IFunctionCallbackArgs&args);
	bool removeEventListener(IFunctionCallbackArgs&args);
	bool dispatchEvent(IFunctionCallbackArgs&args);
	bool AddEventListener(const HandleContext& context, const  std::string& szName, const ValueBase&vFunc, bool bAddTail=true);
	bool RemoveEventListener(const HandleContext& context, const  std::string szName,const ValueBase&vFunc);

	virtual void ExecEventListenerAsync(const HandleContext& context, const char*eventName);//����һ��mainloopʱִ���¼�
//	virtual void ExecEventListenerAsyncFromThread(const char*eventName);//����һ��mainloopʱִ���¼������߳�����ã�
	virtual int ExecEventListener(const HandleContext& context, const char*eventName,ValueBase*pArg=nullptr);//����ִ���¼������سɹ�ִ���¼��Ĵ���
	void ExecTouchEvent(const HandleContext&context, JSVM::_TouchEvent* pevent);
	DXPOINT GetXYInScreen();
	
};

