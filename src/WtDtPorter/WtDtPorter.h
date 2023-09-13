/*!
 * \file WtDtPorter.h
 * \project	WonderTrader
 *
 * \author Wesley
 * \date 2020/03/30
 * 
 * \brief 
 */
#pragma once
#include "PorterDefs.h"


#ifdef __cplusplus
extern "C"
{
#endif

	EXPORT_FLAG void		initialize(WtString cfgFile, WtString logCfg, bool bCfgFile, bool bLogCfgFile);
	EXPORT_FLAG void		start(bool bAsync = false);

	EXPORT_FLAG	WtString	get_version();
	EXPORT_FLAG	void		write_log(unsigned int level, const char* message, const char* catName);


#pragma region "��չParser�ӿ�"
	/*
	 *	����ExtParser
	 *	@id		parserid
	 *	@return	�����Ƿ�ɹ�
	 */
	EXPORT_FLAG	bool		create_ext_parser(const char* id);

	/*
	 *	ע��ExtParser�Ļص�����
	 *	@cbEvt	����������¼��ص���������Ҫ�����ӡ��رա���¼���¼�
	 *	@cbSub	���鶩�Ľ���ص�
	 */
	EXPORT_FLAG void		register_parser_callbacks(FuncParserEvtCallback cbEvt, FuncParserSubCallback cbSub);

	/*
	 *	��ײ�����tick����
	 *	@id			parserid
	 *	@curTick	����tick����
	 *	@procFlag	�����ǣ�0-��Ƭ���飬���账��(ParserUDP)��1-�������գ���Ҫ��Ƭ(���ڸ�·ͨ��)��2-������գ���Ҫ�����ۼӣ���Ҫ������ߡ�tick��m1��m5�����Զ��ۼӵģ�����������飩
	 */
	EXPORT_FLAG	void		parser_push_quote(const char* id, WTSTickStruct* curTick, WtUInt32 uProcFlag);
#pragma endregion "��չParser�ӿ�"

#pragma region "��չDumper�ӿ�"
	EXPORT_FLAG	bool		create_ext_dumper(const char* id);

	EXPORT_FLAG void		register_extended_dumper(FuncDumpBars barDumper, FuncDumpTicks tickDumper);

	EXPORT_FLAG void		register_extended_hftdata_dumper(FuncDumpOrdQue ordQueDumper, FuncDumpOrdDtl ordDtlDumper, FuncDumpTrans transDumper);
#pragma endregion "��չDumper�ӿ�"

#ifdef __cplusplus
}
#endif