#pragma once
//�������Žӿ�
class AudioInterface
{
public:
	AudioInterface();
	virtual ~AudioInterface();
	virtual bool Release() = 0;


	virtual bool Open(const char*szFileName)=0;
	virtual bool Play(unsigned long dwFrom, bool bRepeat) = 0;//ʱ�䵥λΪ����
	virtual bool Pause() = 0;
	virtual bool Stop() = 0;
	virtual bool Seek(unsigned long dwTo) = 0;
	virtual unsigned long GetLength() = 0;
	virtual unsigned long GetCurrentPosition() = 0;
	virtual bool Close() = 0;
	virtual bool isOpen() = 0;
	virtual bool isStop() = 0;
	virtual AudioInterface*Create() = 0;
    virtual void update() = 0;
};

