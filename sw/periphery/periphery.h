#define CALC_MASK(width, pos) \
    ((width) == 32 ? 0xFFFFFFFF : (((1u << width) - 1u) << (pos)))

 

#define INIT_DATE_ADDR              (0*4u) // r/w
#define INIT_DATE_WIDTH             (32u)
#define INIT_DATE_POS               (0u)
#define INIT_DATE_MASK              CALC_MASK(INIT_DATE_WIDTH, INIT_DATE_POS)

#define DATE_ADDR                   (1*4u) // r/o
#define DATE_WIDTH                  (32u)
#define DATE_POS                    (0u)
#define DATE_MASK                   CALC_MASK(DATE_WIDTH, DATE_POS)

#define INIT_CLOCK_ADDR             (2*4u) // r/w
#define INIT_CLOCK_DATA_WIDTH       (22u)
#define INIT_CLOCK_DATA_POS         (0u)
#define INIT_CLOCK_DATA_MASK        CALC_MASK(INIT_CLOCK_DATA_WIDTH, INIT_CLOCK_DATA_POS)

#define CLOCK_ADDR                  (3*4u) // r/o
#define CLOCK_DATA_WIDTH            (22u)
#define CLOCK_DATA_POS              (0u)
#define CLOCK_DATA_MASK             CALC_MASK(CLOCK_DATA_WIDTH, CLOCK_DATA_POS)

#define INIT_SEC_CNT_ADDR           (4*4u)
#define INIT_SEC_CNT_WIDTH          (10u)
#define INIT_SEC_CNT_POS            (0u)
#define INIT_SEC_CNT_MASK           CALC_MASK(INIT_SEC_CNT_WIDTH, INIT_SEC_CNT_POS)

#define ALARM_DATE_ADDR             (5*4u) // r/w
#define ALARM_DATE_WIDTH            (32u)
#define ALARM_DATE_POS              (0u)
#define ALARM_DATE_MASK             CALC_MASK(ALARM_DATE_WIDTH, ALARM_DATE_POS)

#define ALARM_CLOCK_ADDR            (6*4u) // r/w
#define ALARM_CLOCK_DATA_WIDTH      (22u)
#define ALARM_CLOCK_DATA_POS        (0u)
#define ALARM_CLOCK_DATA_MASK       CALC_MASK(ALARM_CLOCK_DATA_WIDTH, ALARM_CLOCK_DATA_POS)
#define ALARM_CLOCK_MATCH_MSK_WIDTH (6u)
#define ALARM_CLOCK_MATCH_MSK_POS   (24u)
#define ALARM_CLOCK_MATCH_MSK_MASK  CALC_MASK(ALARM_CLOCK_MATCH_MSK_WIDTH, ALARM_CLOCK_MATCH_MSK_POS)
#define ALARM_CLOCK_EN_WIDTH        (1u)
#define ALARM_CLOCK_EN_POS          (31u)
#define ALARM_CLOCK_EN_MASK         CALC_MASK(ALARM_CLOCK_EN_WIDTH, ALARM_CLOCK_EN_POS)

#define TIMER_CFG_ADDR              (7*4u) // r/w
#define TIMER_CFG_TARGET_WIDTH      (17u)
#define TIMER_CFG_TARGET_POS        (0u)
#define TIMER_CFG_TARGET_MASK       CALC_MASK(TIMER_CFG_TARGET_WIDTH, TIMER_CFG_TARGET_POS)
#define TIMER_CFG_RETRIG_WIDTH      (1u)
#define TIMER_CFG_RETRIG_POS        (30u)
#define TIMER_CFG_RETRIG_MASK       CALC_MASK(TIMER_CFG_RETRIG_WIDTH, TIMER_CFG_RETRIG_POS)
#define TIMER_CFG_EN_WIDTH          (1u)
#define TIMER_CFG_EN_POS            (31u)
#define TIMER_CFG_EN_MASK           CALC_MASK(TIMER_CFG_EN_WIDTH, TIMER_CFG_EN_POS)

#define TIMER_VAL_ADDR              (8*4u) // r/o
#define TIMER_VAL_WIDTH             (17u)
#define TIMER_VAL_POS               (0u)
#define TIMER_VAL_MASK              CALC_MASK(TIMER_VAL_WIDTH, TIMER_VAL_POS)

#define CALIBRE_ADDR                (9*4u) // r/w
#define CALIBRE_WIDTH               (16u)
#define CALIBRE_POS                 (0u)
#define CALIBRE_MASK                CALC_MASK(CALIBRE_WIDTH, CALIBRE_POS)

#define EVENT_FLAG_ADDR             (10*4u) // w1c
#define EVENT_FLAG_ALARM_WIDTH      (1u)
#define EVENT_FLAG_ALARM_POS        (0u)
#define EVENT_FLAG_ALARM_MASK       CALC_MASK(EVENT_FLAG_ALARM_WIDTH, EVENT_FLAG_ALARM_POS)
#define EVENT_FLAG_TIMER_WIDTH      (1u)
#define EVENT_FLAG_TIMER_POS        (1u)
#define EVENT_FLAG_TIMER_MASK       CALC_MASK(EVENT_FLAG_TIMER_WIDTH, EVENT_FLAG_TIMER_POS)

#define UPDATE_ADDR                 (11*4u) // w1u
#define UPDATE_DATE_WIDTH           (1u)
#define UPDATE_DATE_POS             (0u)
#define UPDATE_DATE_MASK            CALC_MASK(UPDATE_DATE_WIDTH, UPDATE_DATE_POS)
#define UPDATE_CLOCK_WIDTH          (1u)
#define UPDATE_CLOCK_POS            (1u)
#define UPDATE_CLOCK_MASK           CALC_MASK(UPDATE_CLOCK_WIDTH, UPDATE_CLOCK_POS)
#define UPDATE_ALARM_DATE_WIDTH     (1u)
#define UPDATE_ALARM_DATE_POS       (2u)
#define UPDATE_ALARM_DATE_MASK      CALC_MASK(UPDATE_ALARM_DATE_WIDTH, UPDATE_ALARM_DATE_POS)
#define UPDATE_ALARM_CLOCK_WIDTH    (1u)
#define UPDATE_ALARM_CLOCK_POS      (3u)
#define UPDATE_ALARM_CLOCK_MASK     CALC_MASK(UPDATE_ALARM_CLOCK_WIDTH, UPDATE_ALARM_CLOCK_POS)
#define UPDATE_TIMER_WIDTH          (1u)
#define UPDATE_TIMER_POS            (4u)
#define UPDATE_TIMER_MASK           CALC_MASK(UPDATE_TIMER_WIDTH, UPDATE_TIMER_POS)
#define UPDATE_CALIBRE_WIDTH        (1u)
#define UPDATE_CALIBRE_POS          (5u)
#define UPDATE_CALIBRE_MASK         CALC_MASK(UPDATE_CALIBRE_WIDTH, UPDATE_CALIBRE_POS)

#define APPLIED_ADDR                (12*4u) // r/o
#define APPLIED_DATE_WIDTH          (1u)
#define APPLIED_DATE_POS            (0u)
#define APPLIED_DATE_MASK           CALC_MASK(APPLIED_DATE_WIDTH, APPLIED_DATE_POS)
#define APPLIED_CLOCK_WIDTH         (1u)
#define APPLIED_CLOCK_POS           (1u)
#define APPLIED_CLOCK_MASK          CALC_MASK(APPLIED_CLOCK_WIDTH, APPLIED_CLOCK_POS)
#define APPLIED_ALARM_DATE_WIDTH    (1u)
#define APPLIED_ALARM_DATE_POS      (2u)
#define APPLIED_ALARM_DATE_MASK     CALC_MASK(APPLIED_ALARM_DATE_WIDTH, APPLIED_ALARM_DATE_POS)
#define APPLIED_ALARM_CLOCK_WIDTH   (1u)
#define APPLIED_ALARM_CLOCK_POS     (3u)
#define APPLIED_ALARM_CLOCK_MASK    CALC_MASK(APPLIED_ALARM_CLOCK_WIDTH, APPLIED_ALARM_CLOCK_POS)
#define APPLIED_CALIBRE_WIDTH       (1u)
#define APPLIED_CALIBRE_POS         (4u)
#define APPLIED_CALIBRE_MASK        CALC_MASK(APPLIED_CALIBRE_WIDTH, APPLIED_CALIBRE_POS)

#define TCM_BA   (0x00000000)
#define TCM_SIZE (256 * 1024u)

#define PERIPHERY_BA (TCM_BA + TCM_SIZE)
#define EF_TCC32_BA  (PERIPHERY_BA)
#define RTC_BA       (PERIPHERY_BA + 0x1000)

typedef struct
{
    volatile uint32_t init_date   ; // r/w
    volatile uint32_t date        ; // r/o
    volatile uint32_t init_clock  ; // r/w
    volatile uint32_t clock       ; // r/o
    volatile uint32_t init_sec_cnt; // r/w
    volatile uint32_t alarm_date  ; // r/w
    volatile uint32_t alarm_clock ; // r/w
    volatile uint32_t timer_cfg   ; // r/w
    volatile uint32_t timer_val   ; // r/o
    volatile uint32_t calibre     ; // r/w
    volatile uint32_t event_flag  ; // w1c
    volatile uint32_t update      ; // w1u (write 1 update)
    volatile uint32_t applied     ; // r/o
} rtc_t; 