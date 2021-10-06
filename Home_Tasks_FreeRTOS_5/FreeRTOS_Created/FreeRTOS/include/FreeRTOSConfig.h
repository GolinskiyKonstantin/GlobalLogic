#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H
 
 // Использовать вытесняющую многозадачность, Если этот параметр поставить в 0, то получим кооперативку, 
 // с требованием вызывать taskYIELD() для отдачи управления диспетчеру.
#define configUSE_PREEMPTION					1	// 1

// какую память используем под задачи ( обычно динамическая )
#define configSUPPORT_STATIC_ALLOCATION			0   // 0	xTaskCreateStatic()
#define configSUPPORT_DYNAMIC_ALLOCATION		1	// 1	xTaskCreate()

// Использовать ли платформенно зависимые способы переключения задач. 
// Некоторые контроллеры имеют разные хитрые аппаратные механизмы заточенные 
// под работу с ОС и ОС может их использовать, но для этого ей надо это разрешить
#define configUSE_PORT_OPTIMISED_TASK_SELECTION	0	// 0

// Использовать ли IDLE без тиков. В этом режиме таймер в IDLE глушится 
// и не генерирует тики зря, полезно малопотребляющих решений.
//  Реализации с низким энергопотреблением без тиков доступны не для всех портов FreeRTOS.
#define configUSE_TICKLESS_IDLE					0	// 0

// Частота на которой будет тикать проц. Нужна для вычисления задержек. 
// Введите частоту в Гц, с которой будут выполняться внутренние часы, управляющие периферийным устройством, 
// используемым для генерации прерывания по тикам - обычно это те же часы, которые управляют внутренними часами ЦП. 
// Это значение требуется для правильной настройки периферийных устройств таймера.
// Я разгоняю до 72МГЦ потому выставляю тут такое значение.
#define configCPU_CLOCK_HZ						( ( unsigned long ) 72000000 )	// ( ( unsigned long ) 72000000 )
	
// Частота тикового прерывания ОСРВ
// Все демонстрационные приложения ОСРВ используют тиковую частоту 1000 Гц.
#define configTICK_RATE_HZ						( ( TickType_t ) 1000 )	// ( ( TickType_t ) 1000 )

// Количество приоритетов задач
// Каждый доступный приоритет потребляет немного оперативной памяти в ядре RTOS, поэтому 
// это значение не должно быть больше, чем фактически требуется для вашего приложения.
#define configMAX_PRIORITIES					5	// 5

// Размер стека, используемого бездействующей задачей.
// размер стека указывается в словах, а не в байтах. Если каждый элемент, помещенный в стек, является 32-битным, 
// то размер стека 100 означает 400 байтов (каждый 32-битный элемент стека занимает 4 байта).
#define configMINIMAL_STACK_SIZE				128	// 128

// Размер суммарной кучи. Области памяти задачи, где лежит и стек и локальные переменные какие то. 
// Т.е. тут мы укзываем сколько вообще у нас места. Зависит от доступной оперативки. 
// У нас в STM32F103C8T6 ее 20кБ, но может быть некий запас под глобальные переменные какие. 
// Потому 3кБ оставляем себе, а остальное отдаем ОС.
#define configTOTAL_HEAP_SIZE					( ( size_t ) ( 17 * 1024 ) )	// ( ( size_t ) ( 17 * 1024 ) )

// Для отладочных целей можно задавать каждой задаче символическое имя. Это имя естественно ест немного памяти. 
// Вот тут можно указать строку какой длины мы допускаем для этого безобразия.
#define configMAX_TASK_NAME_LEN					16 	// 16

// Разрядность таймера ОС. 1—16 бит, 0—32 бита. У STM32 SysTick 24 разрядный, поэтому оставляем тут 0.
#define configUSE_16_BIT_TICKS					0 	// 0

// Этот параметр определяет поведение задач с приоритетом IDLE болтающихся одновременно с IDLE ядра. 
// Если стоит 1, то ядро будет отдавать управление сразу же как только задача станет готовой к запуску. 
// А если оставить 0, то время будет равномерно делиться между задачами с приоритетом IDLE и IDLE ядра.
#define configIDLE_SHOULD_YIELD					1 	// 1

//----------------------------------------------------------------------------------------------------
// Это конфигурация на использование мутексов и семафоров. 
// Т.е. можно поотрубать ненужное, чтобы память не ело зря
#define configUSE_MUTEXES						1	// 1
#define configUSE_RECURSIVE_MUTEXES				1	// 1
#define configUSE_COUNTING_SEMAPHORES			1	// 1
//----------------------------------------------------------------------------------------------------


// Установите значение 1, чтобы включить «альтернативные» функции очереди в сборку, или 0, 
// чтобы исключить «альтернативные» функции очереди из сборки. 
// Альтернативный API описан в заголовочном файле queue.h. 
// Альтернативный API устарел и не должен использоваться в новых проектах .
#define configUSE_ALTERNATIVE_API				0 /* Deprecated! */	// 0


#define configQUEUE_REGISTRY_SIZE				10	// 10

// Установите 1, чтобы включить функциональность набора очередей (возможность блокировать
// или отложить на несколько очередей и семафоров), или 0, чтобы пропустить функциональность набора очередей
#define configUSE_QUEUE_SETS					0	// 0


#define configUSE_TIME_SLICING					0	// 0
#define configUSE_NEWLIB_REENTRANT				0	// 0
#define configENABLE_BACKWARD_COMPATIBILITY		0	// 0
 
/* Hook function related definitions. */
// Установите 1, если вы хотите использовать ловушку бездействия , или 0, чтобы опустить ловушку бездействия.
// В FreeRTOS мы можем поставить перехват IDLE, т.е. при попадании в Idle будет выполнена некая функция.
// Например загон проца в спячку или еще какая нужна вещь. Если Hook на IDLE не используется, то 0.
#define configUSE_IDLE_HOOK						0	// 0

// Аналогичная функция, но про перехват диспетчера. 
// Т.е. можно поставить зацепку за диспетчер и выполнять какую-нибудь фигню каждый тик.
#define configUSE_TICK_HOOK						0	// 0


#define configCHECK_FOR_STACK_OVERFLOW			0	// 0
#define configUSE_MALLOC_FAILED_HOOK			0	// 0
 
/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS			0	// 0

// Используем ли мы отладочные примочки ОС.
#define configUSE_TRACE_FACILITY				0	// 0

// Установите configUSE_TRACE_FACILITY и configUSE_STATS_FORMATTING_FUNCTIONS в 1, 
// чтобы включить в сборку функции vTaskList () и vTaskGetRunTimeStats () . 
// Установка любого значения на 0 приведет к исключению vTaskList () и vTaskGetRunTimeStates () из сборки.
#define configUSE_STATS_FORMATTING_FUNCTIONS	0	// 0
 
/* Co-routine related definitions. */
//--------------------------------------------------------------------------------------------------------
// Используются ли сопрограммы и приоритеты для них.
#define configUSE_CO_ROUTINES					0	// 0
#define configMAX_CO_ROUTINE_PRIORITIES			2	// 2
//--------------------------------------------------------------------------------------------------------


/* Software timer related definitions. */
// Установите значение 1, чтобы включить функцию программного таймера, или 0, чтобы исключить функцию программного таймера.
#define configUSE_TIMERS						1	// 1

// Устанавливает приоритет задачи службы / демона программного таймера
#define configTIMER_TASK_PRIORITY				3	// 3

// Устанавливает длину очереди команд программного таймера
#define configTIMER_QUEUE_LENGTH				10	// 10

// Устанавливает глубину стека, выделенную для задачи службы / демона программного таймера
#define configTIMER_TASK_STACK_DEPTH			configMINIMAL_STACK_SIZE
 
/* Interrupt nesting behaviour configuration. */
//--------------------------------------------------------------------------------------------------------
// группа настройки приоритетов прерываний.
// у нас есть 16 уровней приоритетов от старшего к младшему: 0х00, 0х10, 0х20, 0х30…0xF0
// Т.е. 255 это уровень 0xF0 — самый младший, а 191 уровень 0xB0 и, таким образом, все прерывания в 
// которых мы можем использовать API фукнции должны быть сконфигурированы с приоритетом от 0xF0 до 0xB0, не старше. 
// Иначе будет трудноуловимый глюк. Прерывания же не использующие API могут быть с каким угодно приоритетом 
// от самого низкого до самого старшего.
#define configKERNEL_INTERRUPT_PRIORITY			255	// 255
#define configMAX_SYSCALL_INTERRUPT_PRIORITY	191	// 191
//--------------------------------------------------------------------------------------------------------
 
 
 
/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
//---------------------------------------------------------------------------------------------------------
// группа позволяет включать-выключать ненужные функции, сокращая размер который ОС занимает во флеше.
#define INCLUDE_vTaskPrioritySet				1	// 1
#define INCLUDE_uxTaskPriorityGet				1	// 1
#define INCLUDE_vTaskDelete						1	// 0
#define INCLUDE_vTaskCleanUpResources			1	// 1
#define INCLUDE_vTaskSuspend					1	// 1
#define INCLUDE_vTaskDelayUntil					1	// 1
#define INCLUDE_vTaskDelay						1	// 1
#define INCLUDE_xResumeFromISR					1	// 1
#define INCLUDE_xTaskGetSchedulerState			1	// 1
#define INCLUDE_xTaskGetCurrentTaskHandle		0	// 0
#define INCLUDE_uxTaskGetStackHighWaterMark		0	// 0
#define INCLUDE_xTaskGetIdleTaskHandle			0	// 0
#define INCLUDE_xTimerGetTimerDaemonTaskHandle	0	// 0
#define INCLUDE_pcTaskGetTaskName				0	// 0
#define INCLUDE_eTaskGetState					0	// 0
#define INCLUDE_xEventGroupSetBitFromISR		1	// 1
#define INCLUDE_xTimerPendFunctionCall			1	// 1
//---------------------------------------------------------------------------------------------------------
 
 
//---------------------------------------------------------------------------------------------------------
// мы привяжем вектора прерываний на диспетчер ОС. Как вы можете видеть
// SysTick используется как таймер службы диспетчера. У другого МК тут можно повесить
// Другой таймер.
#define xPortSysTickHandler 		SysTick_Handler
#define xPortPendSVHandler 			PendSV_Handler
#define vPortSVCHandler 			SVC_Handler
//---------------------------------------------------------------------------------------------------------
 
#endif /* FREERTOS_CONFIG_H */
