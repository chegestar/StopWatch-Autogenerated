/*
 * File: SWatch.c
 *
 * Code generated for Simulink model 'SWatch'.
 *
 * Model version                  : 1.124
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Mon Jan 25 15:09:01 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWatch.h"
#include "SWatch_private.h"

/* Named constants for Chart: '<S1>/SWatch' */
#define SWatch_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define SWatch_IN_Timer                ((uint8_T)1U)
#define SWatch_IN_Timer_Finish         ((uint8_T)1U)
#define SWatch_IN_Timer_Start          ((uint8_T)2U)
#define SWatch_IN_Timeset              ((uint8_T)1U)
#define SWatch_IN_alarmmode            ((uint8_T)1U)
#define SWatch_IN_sethours             ((uint8_T)2U)
#define SWatch_IN_sethours_a           ((uint8_T)1U)
#define SWatch_IN_setminutes           ((uint8_T)3U)
#define SWatch_IN_setminutes_k         ((uint8_T)2U)
#define SWatch_IN_setseconds           ((uint8_T)4U)
#define SWatch_IN_start                ((uint8_T)1U)
#define SWatch_IN_stop                 ((uint8_T)2U)
#define SWatch_IN_swatchmode           ((uint8_T)2U)
#define SWatch_IN_timecount            ((uint8_T)2U)
#define SWatch_IN_timemode             ((uint8_T)3U)
#define SWatch_IN_timermode            ((uint8_T)4U)
#define SWatch_event_Balarm            (5)
#define SWatch_event_Bminus            (2)
#define SWatch_event_Bplus             (1)
#define SWatch_event_Bstart            (7)
#define SWatch_event_Bstop             (8)
#define SWatch_event_Bswatch           (6)
#define SWatch_event_Btime             (3)
#define SWatch_event_Btimer            (4)
#define SWatch_event_ptick             (0)

/* Forward declaration for local functions */
static void SWatch_timermode(const int32_T *sfEvent, uint8_T *SWatch_Y_hours,
  uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  uint8_T *SWatch_Y_mode, uint8_T *SWatch_Y_Timer_exp, DW_SWatch_T *SWatch_DW);
static void SWatch_alarmmode(const int32_T *sfEvent, uint8_T *SWatch_Y_hours,
  uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  uint8_T *SWatch_Y_mode, uint8_T *SWatch_Y_Alarm_signal, DW_SWatch_T *SWatch_DW);
static void SWatch_swatchmode(const int32_T *sfEvent, uint8_T *SWatch_Y_hours,
  uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  uint8_T *SWatch_Y_mode, DW_SWatch_T *SWatch_DW);
static void SWatch_Timeset(const int32_T *sfEvent, uint8_T *SWatch_Y_hours,
  uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, DW_SWatch_T *SWatch_DW);
static void SWatch_chartstep_c3_SWatch(const int32_T *sfEvent, uint8_T
  *SWatch_Y_hours, uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T
  *SWatch_Y_tenths, uint8_T *SWatch_Y_mode, uint8_T *SWatch_Y_Alarm_signal,
  uint8_T *SWatch_Y_Timer_exp, DW_SWatch_T *SWatch_DW);

/* Function for Chart: '<S1>/SWatch' */
static void SWatch_timermode(const int32_T *sfEvent, uint8_T *SWatch_Y_hours,
  uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  uint8_T *SWatch_Y_mode, uint8_T *SWatch_Y_Timer_exp, DW_SWatch_T *SWatch_DW)
{
  boolean_T guard1 = false;
  int32_T tmp;
  uint32_T qY;

  /* During 'timermode': '<S3>:23' */
  if (*sfEvent == SWatch_event_Balarm) {
    /* Transition: '<S3>:46' */
    /* Exit Internal 'timermode': '<S3>:23' */
    /* Exit Internal 'Timer': '<S3>:123' */
    SWatch_DW->is_Timer = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_timermode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_alarmmode;

    /* Entry 'alarmmode': '<S3>:39' */
    *SWatch_Y_mode = 2U;

    /* Entry Internal 'alarmmode': '<S3>:39' */
    /* Transition: '<S3>:82' */
    SWatch_DW->Aminutes = 0U;
    SWatch_DW->Ahours = 0U;
    *SWatch_Y_minutes = SWatch_DW->Aminutes;
    SWatch_DW->Alarm_state = 0U;
    SWatch_DW->mutex = 1U;
    SWatch_DW->is_alarmmode = SWatch_IN_sethours_a;

    /* Entry 'sethours': '<S3>:76' */
    *SWatch_Y_hours = SWatch_DW->Ahours;
  } else if (*sfEvent == SWatch_event_Bswatch) {
    /* Transition: '<S3>:51' */
    /* Exit Internal 'timermode': '<S3>:23' */
    /* Exit Internal 'Timer': '<S3>:123' */
    SWatch_DW->is_Timer = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_timermode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_swatchmode;

    /* Entry 'swatchmode': '<S3>:38' */
    *SWatch_Y_mode = 3U;

    /* Entry Internal 'swatchmode': '<S3>:38' */
    /* Transition: '<S3>:239' */
    SWatch_DW->Ahours = 0U;
    SWatch_DW->Aminutes = 0U;
    SWatch_DW->Aseconds = 0U;
    SWatch_DW->Atenths = 0U;
    SWatch_DW->mutex = 1U;
    SWatch_DW->is_swatchmode = SWatch_IN_stop;

    /* Entry 'stop': '<S3>:207' */
    *SWatch_Y_hours = SWatch_DW->Ahours;
    *SWatch_Y_minutes = SWatch_DW->Aminutes;
    *SWatch_Y_seconds = SWatch_DW->Aseconds;
    *SWatch_Y_tenths = SWatch_DW->Atenths;
  } else if (*sfEvent == SWatch_event_Bstop) {
    /* Transition: '<S3>:336' */
    /* Exit Internal 'timermode': '<S3>:23' */
    /* Exit Internal 'Timer': '<S3>:123' */
    SWatch_DW->is_Timer = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->Aseconds = 0U;
    SWatch_DW->Ahours = 0U;
    SWatch_DW->Aminutes = 0U;
    *SWatch_Y_minutes = SWatch_DW->Aminutes;
    *SWatch_Y_seconds = SWatch_DW->Aseconds;
    *SWatch_Y_Timer_exp = 0U;
    SWatch_DW->is_timermode = SWatch_IN_sethours;

    /* Entry 'sethours': '<S3>:60' */
    *SWatch_Y_hours = SWatch_DW->Ahours;
  } else {
    switch (SWatch_DW->is_timermode) {
     case SWatch_IN_Timer:
      /* During 'Timer': '<S3>:123' */
      if ((SWatch_DW->is_Timer != SWatch_IN_Timer_Finish) && (*sfEvent ==
           SWatch_event_ptick)) {
        /* During 'Timer_Start': '<S3>:160' */
        /* Transition: '<S3>:173' */
        tmp = (int32_T)(SWatch_DW->Atenths + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        SWatch_DW->Atenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 10U * 10U));
        if (SWatch_DW->Atenths == 0) {
          /* Transition: '<S3>:303' */
          if (SWatch_DW->Aseconds > 0) {
            /* Transition: '<S3>:305' */
            /* Transition: '<S3>:163' */
            qY = SWatch_DW->Aseconds - 1U;
            if (qY > SWatch_DW->Aseconds) {
              qY = 0U;
            }

            SWatch_DW->Aseconds = (uint8_T)qY;
            *SWatch_Y_seconds = SWatch_DW->Aseconds;
            SWatch_DW->is_Timer = SWatch_IN_Timer_Start;
          } else if ((SWatch_DW->Aminutes > 0) && (SWatch_DW->Aseconds == 0)) {
            /* Transition: '<S3>:307' */
            /* Transition: '<S3>:163' */
            qY = SWatch_DW->Aminutes - 1U;
            if (qY > SWatch_DW->Aminutes) {
              qY = 0U;
            }

            SWatch_DW->Aminutes = (uint8_T)qY;
            *SWatch_Y_minutes = SWatch_DW->Aminutes;
            SWatch_DW->Aseconds = 59U;
            *SWatch_Y_seconds = SWatch_DW->Aseconds;
            SWatch_DW->is_Timer = SWatch_IN_Timer_Start;
          } else if ((SWatch_DW->Ahours > 0) && (SWatch_DW->Aminutes == 0) &&
                     (SWatch_DW->Aseconds == 0)) {
            /* Transition: '<S3>:308' */
            /* Transition: '<S3>:163' */
            qY = SWatch_DW->Ahours - 1U;
            if (qY > SWatch_DW->Ahours) {
              qY = 0U;
            }

            SWatch_DW->Ahours = (uint8_T)qY;
            *SWatch_Y_hours = SWatch_DW->Ahours;
            SWatch_DW->Aminutes = 59U;
            *SWatch_Y_minutes = 59U;
            SWatch_DW->Aseconds = 59U;
            *SWatch_Y_seconds = 59U;
            SWatch_DW->is_Timer = SWatch_IN_Timer_Start;
          } else if ((SWatch_DW->Ahours == 0) && (SWatch_DW->Aminutes == 0) &&
                     (SWatch_DW->Aseconds == 0)) {
            /* Transition: '<S3>:309' */
            SWatch_DW->is_Timer = SWatch_IN_Timer_Finish;

            /* Entry 'Timer_Finish': '<S3>:183' */
            *SWatch_Y_Timer_exp = 1U;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      } else {
        /* During 'Timer_Finish': '<S3>:183' */
      }
      break;

     case SWatch_IN_sethours:
      /* During 'sethours': '<S3>:60' */
      if (*sfEvent == SWatch_event_Btimer) {
        /* Transition: '<S3>:64' */
        SWatch_DW->is_timermode = SWatch_IN_setminutes;

        /* Entry 'setminutes': '<S3>:61' */
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
      } else if (*sfEvent == SWatch_event_Bplus) {
        /* Transition: '<S3>:66' */
        tmp = (int32_T)(SWatch_DW->Ahours + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        SWatch_DW->Ahours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 24U * 24U));
        SWatch_DW->is_timermode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:60' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
      } else if ((*sfEvent == SWatch_event_Bminus) && (SWatch_DW->Ahours == 0))
      {
        /* Transition: '<S3>:68' */
        SWatch_DW->Ahours = 23U;
        SWatch_DW->is_timermode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:60' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
      } else if (*sfEvent == SWatch_event_Bminus) {
        /* Transition: '<S3>:72' */
        qY = SWatch_DW->Ahours - 1U;
        if (qY > SWatch_DW->Ahours) {
          qY = 0U;
        }

        SWatch_DW->Ahours = (uint8_T)qY;
        SWatch_DW->is_timermode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:60' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
      } else {
        if ((*sfEvent == SWatch_event_Bstart) && ((SWatch_DW->Ahours > 0) ||
             (SWatch_DW->Aminutes > 0) || (SWatch_DW->Aseconds > 0))) {
          /* Transition: '<S3>:120' */
          SWatch_DW->is_timermode = SWatch_IN_Timer;

          /* Entry Internal 'Timer': '<S3>:123' */
          /* Transition: '<S3>:310' */
          SWatch_DW->is_Timer = SWatch_IN_Timer_Start;
        }
      }
      break;

     case SWatch_IN_setminutes:
      /* During 'setminutes': '<S3>:61' */
      if (*sfEvent == SWatch_event_Btimer) {
        /* Transition: '<S3>:276' */
        SWatch_DW->is_timermode = SWatch_IN_setseconds;

        /* Entry 'setseconds': '<S3>:273' */
        *SWatch_Y_seconds = SWatch_DW->Aseconds;
      } else if (*sfEvent == SWatch_event_Bplus) {
        /* Transition: '<S3>:67' */
        tmp = (int32_T)(SWatch_DW->Aminutes + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        SWatch_DW->Aminutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));
        SWatch_DW->is_timermode = SWatch_IN_setminutes;

        /* Entry 'setminutes': '<S3>:61' */
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
      } else if ((*sfEvent == SWatch_event_Bminus) && (SWatch_DW->Aminutes == 0))
      {
        /* Transition: '<S3>:69' */
        SWatch_DW->Aminutes = 59U;
        SWatch_DW->is_timermode = SWatch_IN_setminutes;

        /* Entry 'setminutes': '<S3>:61' */
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
      } else if (*sfEvent == SWatch_event_Bminus) {
        /* Transition: '<S3>:75' */
        qY = SWatch_DW->Aminutes - 1U;
        if (qY > SWatch_DW->Aminutes) {
          qY = 0U;
        }

        SWatch_DW->Aminutes = (uint8_T)qY;
        SWatch_DW->is_timermode = SWatch_IN_setminutes;

        /* Entry 'setminutes': '<S3>:61' */
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
      } else {
        if ((*sfEvent == SWatch_event_Bstart) && ((SWatch_DW->Ahours > 0) ||
             (SWatch_DW->Aminutes > 0) || (SWatch_DW->Aseconds > 0))) {
          /* Transition: '<S3>:121' */
          SWatch_DW->is_timermode = SWatch_IN_Timer;

          /* Entry Internal 'Timer': '<S3>:123' */
          /* Transition: '<S3>:310' */
          SWatch_DW->is_Timer = SWatch_IN_Timer_Start;
        }
      }
      break;

     default:
      /* During 'setseconds': '<S3>:273' */
      if (*sfEvent == SWatch_event_Btimer) {
        /* Transition: '<S3>:299' */
        SWatch_DW->is_timermode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:60' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
      } else if (*sfEvent == SWatch_event_Bplus) {
        /* Transition: '<S3>:272' */
        tmp = (int32_T)(SWatch_DW->Aseconds + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        SWatch_DW->Aseconds = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));
        SWatch_DW->is_timermode = SWatch_IN_setseconds;

        /* Entry 'setseconds': '<S3>:273' */
        *SWatch_Y_seconds = SWatch_DW->Aseconds;
      } else if ((*sfEvent == SWatch_event_Bminus) && (SWatch_DW->Aseconds == 0))
      {
        /* Transition: '<S3>:274' */
        SWatch_DW->Aseconds = 59U;
        SWatch_DW->is_timermode = SWatch_IN_setseconds;

        /* Entry 'setseconds': '<S3>:273' */
        *SWatch_Y_seconds = SWatch_DW->Aseconds;
      } else if (*sfEvent == SWatch_event_Bminus) {
        /* Transition: '<S3>:275' */
        qY = SWatch_DW->Aseconds - 1U;
        if (qY > SWatch_DW->Aseconds) {
          qY = 0U;
        }

        SWatch_DW->Aseconds = (uint8_T)qY;
        SWatch_DW->is_timermode = SWatch_IN_setseconds;

        /* Entry 'setseconds': '<S3>:273' */
        *SWatch_Y_seconds = SWatch_DW->Aseconds;
      } else {
        if ((*sfEvent == SWatch_event_Bstart) && ((SWatch_DW->Ahours > 0) ||
             (SWatch_DW->Aminutes > 0) || (SWatch_DW->Aseconds > 0))) {
          /* Transition: '<S3>:278' */
          SWatch_DW->is_timermode = SWatch_IN_Timer;

          /* Entry Internal 'Timer': '<S3>:123' */
          /* Transition: '<S3>:310' */
          SWatch_DW->is_Timer = SWatch_IN_Timer_Start;
        }
      }
      break;
    }

    if (guard1) {
      /* Transition: '<S3>:174' */
      /* Transition: '<S3>:163' */
      SWatch_DW->is_Timer = SWatch_IN_Timer_Start;
    }
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatch_alarmmode(const int32_T *sfEvent, uint8_T *SWatch_Y_hours,
  uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  uint8_T *SWatch_Y_mode, uint8_T *SWatch_Y_Alarm_signal, DW_SWatch_T *SWatch_DW)
{
  int32_T tmp;
  uint32_T qY;

  /* During 'alarmmode': '<S3>:39' */
  if (*sfEvent == SWatch_event_Btimer) {
    /* Transition: '<S3>:43' */
    /* Exit Internal 'alarmmode': '<S3>:39' */
    SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_timermode;

    /* Entry 'timermode': '<S3>:23' */
    *SWatch_Y_mode = 1U;

    /* Entry Internal 'timermode': '<S3>:23' */
    /* Transition: '<S3>:62' */
    SWatch_DW->Aminutes = 0U;
    SWatch_DW->Ahours = 0U;
    SWatch_DW->Aseconds = 0U;
    SWatch_DW->Atenths = 0U;
    *SWatch_Y_minutes = SWatch_DW->Aminutes;
    *SWatch_Y_seconds = SWatch_DW->Aseconds;
    SWatch_DW->mutex = 1U;
    SWatch_DW->is_timermode = SWatch_IN_sethours;

    /* Entry 'sethours': '<S3>:60' */
    *SWatch_Y_hours = SWatch_DW->Ahours;
  } else if (*sfEvent == SWatch_event_Bswatch) {
    /* Transition: '<S3>:49' */
    /* Exit Internal 'alarmmode': '<S3>:39' */
    SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_swatchmode;

    /* Entry 'swatchmode': '<S3>:38' */
    *SWatch_Y_mode = 3U;

    /* Entry Internal 'swatchmode': '<S3>:38' */
    /* Transition: '<S3>:239' */
    SWatch_DW->Ahours = 0U;
    SWatch_DW->Aminutes = 0U;
    SWatch_DW->Aseconds = 0U;
    SWatch_DW->Atenths = 0U;
    SWatch_DW->mutex = 1U;
    SWatch_DW->is_swatchmode = SWatch_IN_stop;

    /* Entry 'stop': '<S3>:207' */
    *SWatch_Y_hours = SWatch_DW->Ahours;
    *SWatch_Y_minutes = SWatch_DW->Aminutes;
    *SWatch_Y_seconds = SWatch_DW->Aseconds;
    *SWatch_Y_tenths = SWatch_DW->Atenths;
  } else if (*sfEvent == SWatch_event_Bstop) {
    /* Transition: '<S3>:337' */
    /* Exit Internal 'alarmmode': '<S3>:39' */
    *SWatch_Y_Alarm_signal = 0U;

    /* Entry Internal 'alarmmode': '<S3>:39' */
    /* Transition: '<S3>:82' */
    SWatch_DW->Aminutes = 0U;
    SWatch_DW->Ahours = 0U;
    *SWatch_Y_minutes = SWatch_DW->Aminutes;
    SWatch_DW->Alarm_state = 0U;
    SWatch_DW->mutex = 1U;
    SWatch_DW->is_alarmmode = SWatch_IN_sethours_a;

    /* Entry 'sethours': '<S3>:76' */
    *SWatch_Y_hours = SWatch_DW->Ahours;
  } else if (SWatch_DW->is_alarmmode == SWatch_IN_sethours_a) {
    /* During 'sethours': '<S3>:76' */
    if (*sfEvent == SWatch_event_Balarm) {
      /* Transition: '<S3>:77' */
      SWatch_DW->is_alarmmode = SWatch_IN_setminutes_k;

      /* Entry 'setminutes': '<S3>:81' */
      *SWatch_Y_minutes = SWatch_DW->Aminutes;
    } else if (*sfEvent == SWatch_event_Bplus) {
      /* Transition: '<S3>:83' */
      tmp = (int32_T)(SWatch_DW->Ahours + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      SWatch_DW->Ahours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)((uint8_T)
        tmp / 24U * 24U));
      SWatch_DW->is_alarmmode = SWatch_IN_sethours_a;

      /* Entry 'sethours': '<S3>:76' */
      *SWatch_Y_hours = SWatch_DW->Ahours;
    } else if ((*sfEvent == SWatch_event_Bminus) && (SWatch_DW->Ahours == 0)) {
      /* Transition: '<S3>:84' */
      SWatch_DW->Ahours = 23U;
      SWatch_DW->is_alarmmode = SWatch_IN_sethours_a;

      /* Entry 'sethours': '<S3>:76' */
      *SWatch_Y_hours = SWatch_DW->Ahours;
    } else if (*sfEvent == SWatch_event_Bminus) {
      /* Transition: '<S3>:86' */
      qY = SWatch_DW->Ahours - 1U;
      if (qY > SWatch_DW->Ahours) {
        qY = 0U;
      }

      SWatch_DW->Ahours = (uint8_T)qY;
      SWatch_DW->is_alarmmode = SWatch_IN_sethours_a;

      /* Entry 'sethours': '<S3>:76' */
      *SWatch_Y_hours = SWatch_DW->Ahours;
    } else {
      if (*sfEvent == SWatch_event_Bstart) {
        /* Transition: '<S3>:254' */
        SWatch_DW->Alarm_state = 1U;
        SWatch_DW->Alarm_h = SWatch_DW->Ahours;
        SWatch_DW->Alarm_m = SWatch_DW->Aminutes;
        SWatch_DW->is_alarmmode = SWatch_IN_sethours_a;

        /* Entry 'sethours': '<S3>:76' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
      }
    }
  } else {
    /* During 'setminutes': '<S3>:81' */
    if (*sfEvent == SWatch_event_Balarm) {
      /* Transition: '<S3>:80' */
      SWatch_DW->is_alarmmode = SWatch_IN_sethours_a;

      /* Entry 'sethours': '<S3>:76' */
      *SWatch_Y_hours = SWatch_DW->Ahours;
    } else if (*sfEvent == SWatch_event_Bplus) {
      /* Transition: '<S3>:79' */
      tmp = (int32_T)(SWatch_DW->Aminutes + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      SWatch_DW->Aminutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
        ((uint8_T)tmp / 60U * 60U));
      SWatch_DW->is_alarmmode = SWatch_IN_setminutes_k;

      /* Entry 'setminutes': '<S3>:81' */
      *SWatch_Y_minutes = SWatch_DW->Aminutes;
    } else if ((*sfEvent == SWatch_event_Bminus) && (SWatch_DW->Aminutes == 0))
    {
      /* Transition: '<S3>:85' */
      SWatch_DW->Aminutes = 59U;
      SWatch_DW->is_alarmmode = SWatch_IN_setminutes_k;

      /* Entry 'setminutes': '<S3>:81' */
      *SWatch_Y_minutes = SWatch_DW->Aminutes;
    } else if (*sfEvent == SWatch_event_Bminus) {
      /* Transition: '<S3>:78' */
      qY = SWatch_DW->Aminutes - 1U;
      if (qY > SWatch_DW->Aminutes) {
        qY = 0U;
      }

      SWatch_DW->Aminutes = (uint8_T)qY;
      SWatch_DW->is_alarmmode = SWatch_IN_setminutes_k;

      /* Entry 'setminutes': '<S3>:81' */
      *SWatch_Y_minutes = SWatch_DW->Aminutes;
    } else {
      if (*sfEvent == SWatch_event_Bstart) {
        /* Transition: '<S3>:255' */
        SWatch_DW->Alarm_state = 1U;
        SWatch_DW->Alarm_h = SWatch_DW->Ahours;
        SWatch_DW->Alarm_m = SWatch_DW->Aminutes;
        SWatch_DW->is_alarmmode = SWatch_IN_setminutes_k;

        /* Entry 'setminutes': '<S3>:81' */
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
      }
    }
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatch_swatchmode(const int32_T *sfEvent, uint8_T *SWatch_Y_hours,
  uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  uint8_T *SWatch_Y_mode, DW_SWatch_T *SWatch_DW)
{
  int32_T tmp;

  /* During 'swatchmode': '<S3>:38' */
  if (*sfEvent == SWatch_event_Btimer) {
    /* Transition: '<S3>:42' */
    /* Exit Internal 'swatchmode': '<S3>:38' */
    SWatch_DW->is_swatchmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_timermode;

    /* Entry 'timermode': '<S3>:23' */
    *SWatch_Y_mode = 1U;

    /* Entry Internal 'timermode': '<S3>:23' */
    /* Transition: '<S3>:62' */
    SWatch_DW->Aminutes = 0U;
    SWatch_DW->Ahours = 0U;
    SWatch_DW->Aseconds = 0U;
    SWatch_DW->Atenths = 0U;
    *SWatch_Y_minutes = SWatch_DW->Aminutes;
    *SWatch_Y_seconds = SWatch_DW->Aseconds;
    SWatch_DW->mutex = 1U;
    SWatch_DW->is_timermode = SWatch_IN_sethours;

    /* Entry 'sethours': '<S3>:60' */
    *SWatch_Y_hours = SWatch_DW->Ahours;
  } else if (*sfEvent == SWatch_event_Balarm) {
    /* Transition: '<S3>:48' */
    /* Exit Internal 'swatchmode': '<S3>:38' */
    SWatch_DW->is_swatchmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_alarmmode;

    /* Entry 'alarmmode': '<S3>:39' */
    *SWatch_Y_mode = 2U;

    /* Entry Internal 'alarmmode': '<S3>:39' */
    /* Transition: '<S3>:82' */
    SWatch_DW->Aminutes = 0U;
    SWatch_DW->Ahours = 0U;
    *SWatch_Y_minutes = SWatch_DW->Aminutes;
    SWatch_DW->Alarm_state = 0U;
    SWatch_DW->mutex = 1U;
    SWatch_DW->is_alarmmode = SWatch_IN_sethours_a;

    /* Entry 'sethours': '<S3>:76' */
    *SWatch_Y_hours = SWatch_DW->Ahours;
  } else if (SWatch_DW->is_swatchmode == SWatch_IN_start) {
    /* During 'start': '<S3>:229' */
    if (*sfEvent == SWatch_event_Bstop) {
      /* Transition: '<S3>:240' */
      SWatch_DW->is_swatchmode = SWatch_IN_stop;

      /* Entry 'stop': '<S3>:207' */
      *SWatch_Y_hours = SWatch_DW->Ahours;
      *SWatch_Y_minutes = SWatch_DW->Aminutes;
      *SWatch_Y_seconds = SWatch_DW->Aseconds;
      *SWatch_Y_tenths = SWatch_DW->Atenths;
    } else if (*sfEvent == SWatch_event_Bswatch) {
      /* Transition: '<S3>:243' */
      SWatch_DW->Ahours = 0U;
      SWatch_DW->Aminutes = 0U;
      SWatch_DW->Aseconds = 0U;
      SWatch_DW->Atenths = 0U;
      SWatch_DW->is_swatchmode = SWatch_IN_stop;

      /* Entry 'stop': '<S3>:207' */
      *SWatch_Y_hours = SWatch_DW->Ahours;
      *SWatch_Y_minutes = SWatch_DW->Aminutes;
      *SWatch_Y_seconds = SWatch_DW->Aseconds;
      *SWatch_Y_tenths = SWatch_DW->Atenths;
    } else {
      if (*sfEvent == SWatch_event_ptick) {
        /* Transition: '<S3>:222' */
        if (SWatch_DW->Atenths == 0) {
          /* Transition: '<S3>:225' */
          tmp = (int32_T)(SWatch_DW->Aseconds + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->Aseconds = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 60U * 60U));
          if (SWatch_DW->Aseconds == 0) {
            /* Transition: '<S3>:215' */
            tmp = (int32_T)(SWatch_DW->Aminutes + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            SWatch_DW->Aminutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
              ((uint8_T)tmp / 60U * 60U));
            if (SWatch_DW->Aminutes == 0) {
              /* Transition: '<S3>:218' */
              tmp = (int32_T)(SWatch_DW->Ahours + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              SWatch_DW->Ahours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
                ((uint8_T)tmp / 24U * 24U));

              /* Transition: '<S3>:226' */
              tmp = (int32_T)(SWatch_DW->Atenths + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              SWatch_DW->Atenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
                ((uint8_T)tmp / 10U * 10U));
              SWatch_DW->is_swatchmode = SWatch_IN_start;

              /* Entry 'start': '<S3>:229' */
              *SWatch_Y_hours = SWatch_DW->Ahours;
              *SWatch_Y_minutes = SWatch_DW->Aminutes;
              *SWatch_Y_seconds = SWatch_DW->Aseconds;
              *SWatch_Y_tenths = SWatch_DW->Atenths;
            } else {
              /* Transition: '<S3>:219' */
              /* Transition: '<S3>:220' */
              tmp = (int32_T)(SWatch_DW->Atenths + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              SWatch_DW->Atenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
                ((uint8_T)tmp / 10U * 10U));
              SWatch_DW->is_swatchmode = SWatch_IN_start;

              /* Entry 'start': '<S3>:229' */
              *SWatch_Y_hours = SWatch_DW->Ahours;
              *SWatch_Y_minutes = SWatch_DW->Aminutes;
              *SWatch_Y_seconds = SWatch_DW->Aseconds;
              *SWatch_Y_tenths = SWatch_DW->Atenths;
            }
          } else {
            /* Transition: '<S3>:227' */
            /* Transition: '<S3>:220' */
            tmp = (int32_T)(SWatch_DW->Atenths + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            SWatch_DW->Atenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
              ((uint8_T)tmp / 10U * 10U));
            SWatch_DW->is_swatchmode = SWatch_IN_start;

            /* Entry 'start': '<S3>:229' */
            *SWatch_Y_hours = SWatch_DW->Ahours;
            *SWatch_Y_minutes = SWatch_DW->Aminutes;
            *SWatch_Y_seconds = SWatch_DW->Aseconds;
            *SWatch_Y_tenths = SWatch_DW->Atenths;
          }
        } else {
          /* Transition: '<S3>:217' */
          /* Transition: '<S3>:220' */
          tmp = (int32_T)(SWatch_DW->Atenths + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->Atenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 10U * 10U));
          SWatch_DW->is_swatchmode = SWatch_IN_start;

          /* Entry 'start': '<S3>:229' */
          *SWatch_Y_hours = SWatch_DW->Ahours;
          *SWatch_Y_minutes = SWatch_DW->Aminutes;
          *SWatch_Y_seconds = SWatch_DW->Aseconds;
          *SWatch_Y_tenths = SWatch_DW->Atenths;
        }
      }
    }
  } else {
    /* During 'stop': '<S3>:207' */
    if (*sfEvent == SWatch_event_Bstart) {
      /* Transition: '<S3>:230' */
      SWatch_DW->is_swatchmode = SWatch_IN_start;

      /* Entry 'start': '<S3>:229' */
      *SWatch_Y_hours = SWatch_DW->Ahours;
      *SWatch_Y_minutes = SWatch_DW->Aminutes;
      *SWatch_Y_seconds = SWatch_DW->Aseconds;
      *SWatch_Y_tenths = SWatch_DW->Atenths;
    } else {
      if (*sfEvent == SWatch_event_Bswatch) {
        /* Transition: '<S3>:244' */
        SWatch_DW->Ahours = 0U;
        SWatch_DW->Aminutes = 0U;
        SWatch_DW->Aseconds = 0U;
        SWatch_DW->Atenths = 0U;
        SWatch_DW->is_swatchmode = SWatch_IN_stop;

        /* Entry 'stop': '<S3>:207' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
        *SWatch_Y_seconds = SWatch_DW->Aseconds;
        *SWatch_Y_tenths = SWatch_DW->Atenths;
      }
    }
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatch_Timeset(const int32_T *sfEvent, uint8_T *SWatch_Y_hours,
  uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, DW_SWatch_T *SWatch_DW)
{
  int32_T tmp;
  uint32_T qY;

  /* During 'Timeset': '<S3>:315' */
  if ((*sfEvent == SWatch_event_Bstart) && (SWatch_DW->mutex == 0)) {
    /* Transition: '<S3>:318' */
    /* Exit Internal 'Timeset': '<S3>:315' */
    SWatch_DW->is_Timeset = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_TimeCount = SWatch_IN_timecount;
  } else if (SWatch_DW->is_Timeset == SWatch_IN_sethours_a) {
    /* During 'sethours': '<S3>:323' */
    if ((*sfEvent == SWatch_event_Bstop) && (SWatch_DW->mutex == 0)) {
      /* Transition: '<S3>:319' */
      SWatch_DW->is_Timeset = SWatch_IN_setminutes_k;

      /* Entry 'setminutes': '<S3>:322' */
      *SWatch_Y_minutes = SWatch_DW->minutes;
    } else if ((*sfEvent == SWatch_event_Bplus) && (SWatch_DW->mutex == 0)) {
      /* Transition: '<S3>:326' */
      tmp = (int32_T)(SWatch_DW->hours + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      SWatch_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)((uint8_T)
        tmp / 24U * 24U));
      SWatch_DW->is_Timeset = SWatch_IN_sethours_a;

      /* Entry 'sethours': '<S3>:323' */
      *SWatch_Y_hours = SWatch_DW->hours;
      SWatch_DW->seconds = 0U;
      *SWatch_Y_seconds = 0U;
      SWatch_DW->tenths = 0U;
    } else if ((*sfEvent == SWatch_event_Bminus) && (SWatch_DW->hours == 0) &&
               (SWatch_DW->mutex == 0)) {
      /* Transition: '<S3>:325' */
      SWatch_DW->hours = 23U;
      SWatch_DW->is_Timeset = SWatch_IN_sethours_a;

      /* Entry 'sethours': '<S3>:323' */
      *SWatch_Y_hours = SWatch_DW->hours;
      SWatch_DW->seconds = 0U;
      *SWatch_Y_seconds = 0U;
      SWatch_DW->tenths = 0U;
    } else {
      if ((*sfEvent == SWatch_event_Bminus) && (SWatch_DW->mutex == 0)) {
        /* Transition: '<S3>:324' */
        qY = SWatch_DW->hours - 1U;
        if (qY > SWatch_DW->hours) {
          qY = 0U;
        }

        SWatch_DW->hours = (uint8_T)qY;
        SWatch_DW->is_Timeset = SWatch_IN_sethours_a;

        /* Entry 'sethours': '<S3>:323' */
        *SWatch_Y_hours = SWatch_DW->hours;
        SWatch_DW->seconds = 0U;
        *SWatch_Y_seconds = 0U;
        SWatch_DW->tenths = 0U;
      }
    }
  } else {
    /* During 'setminutes': '<S3>:322' */
    if ((*sfEvent == SWatch_event_Bstop) && (SWatch_DW->mutex == 0)) {
      /* Transition: '<S3>:333' */
      SWatch_DW->is_Timeset = SWatch_IN_sethours_a;

      /* Entry 'sethours': '<S3>:323' */
      *SWatch_Y_hours = SWatch_DW->hours;
      SWatch_DW->seconds = 0U;
      *SWatch_Y_seconds = 0U;
      SWatch_DW->tenths = 0U;
    } else if ((*sfEvent == SWatch_event_Bplus) && (SWatch_DW->mutex == 0)) {
      /* Transition: '<S3>:321' */
      tmp = (int32_T)(SWatch_DW->minutes + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      SWatch_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)((uint8_T)
        tmp / 60U * 60U));
      SWatch_DW->is_Timeset = SWatch_IN_setminutes_k;

      /* Entry 'setminutes': '<S3>:322' */
      *SWatch_Y_minutes = SWatch_DW->minutes;
    } else if ((*sfEvent == SWatch_event_Bminus) && (SWatch_DW->minutes == 0) &&
               (SWatch_DW->mutex == 0)) {
      /* Transition: '<S3>:327' */
      SWatch_DW->minutes = 59U;
      SWatch_DW->is_Timeset = SWatch_IN_setminutes_k;

      /* Entry 'setminutes': '<S3>:322' */
      *SWatch_Y_minutes = SWatch_DW->minutes;
    } else {
      if ((*sfEvent == SWatch_event_Bminus) && (SWatch_DW->mutex == 0)) {
        /* Transition: '<S3>:320' */
        qY = SWatch_DW->minutes - 1U;
        if (qY > SWatch_DW->minutes) {
          qY = 0U;
        }

        SWatch_DW->minutes = (uint8_T)qY;
        SWatch_DW->is_Timeset = SWatch_IN_setminutes_k;

        /* Entry 'setminutes': '<S3>:322' */
        *SWatch_Y_minutes = SWatch_DW->minutes;
      }
    }
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatch_chartstep_c3_SWatch(const int32_T *sfEvent, uint8_T
  *SWatch_Y_hours, uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T
  *SWatch_Y_tenths, uint8_T *SWatch_Y_mode, uint8_T *SWatch_Y_Alarm_signal,
  uint8_T *SWatch_Y_Timer_exp, DW_SWatch_T *SWatch_DW)
{
  boolean_T guard1 = false;
  int32_T tmp;

  /* During: SWatch/SWatch */
  /* During 'Control': '<S3>:13' */
  if (*sfEvent == SWatch_event_Btime) {
    /* Transition: '<S3>:45' */
    /* Exit Internal 'Control': '<S3>:13' */
    /* Exit Internal 'alarmmode': '<S3>:39' */
    SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'swatchmode': '<S3>:38' */
    SWatch_DW->is_swatchmode = SWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'timermode': '<S3>:23' */
    /* Exit Internal 'Timer': '<S3>:123' */
    SWatch_DW->is_Timer = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_timermode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_timemode;

    /* Entry 'timemode': '<S3>:22' */
    *SWatch_Y_mode = 0U;
    SWatch_DW->mutex = 0U;
  } else {
    switch (SWatch_DW->is_Control) {
     case SWatch_IN_alarmmode:
      SWatch_alarmmode(sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
                       SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode,
                       SWatch_Y_Alarm_signal, SWatch_DW);
      break;

     case SWatch_IN_swatchmode:
      SWatch_swatchmode(sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
                        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode,
                        SWatch_DW);
      break;

     case SWatch_IN_timemode:
      /* During 'timemode': '<S3>:22' */
      if (*sfEvent == SWatch_event_Btimer) {
        /* Transition: '<S3>:25' */
        SWatch_DW->is_Control = SWatch_IN_timermode;

        /* Entry 'timermode': '<S3>:23' */
        *SWatch_Y_mode = 1U;

        /* Entry Internal 'timermode': '<S3>:23' */
        /* Transition: '<S3>:62' */
        SWatch_DW->Aminutes = 0U;
        SWatch_DW->Ahours = 0U;
        SWatch_DW->Aseconds = 0U;
        SWatch_DW->Atenths = 0U;
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
        *SWatch_Y_seconds = SWatch_DW->Aseconds;
        SWatch_DW->mutex = 1U;
        SWatch_DW->is_timermode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:60' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
      } else if (*sfEvent == SWatch_event_Balarm) {
        /* Transition: '<S3>:47' */
        SWatch_DW->is_Control = SWatch_IN_alarmmode;

        /* Entry 'alarmmode': '<S3>:39' */
        *SWatch_Y_mode = 2U;

        /* Entry Internal 'alarmmode': '<S3>:39' */
        /* Transition: '<S3>:82' */
        SWatch_DW->Aminutes = 0U;
        SWatch_DW->Ahours = 0U;
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
        SWatch_DW->Alarm_state = 0U;
        SWatch_DW->mutex = 1U;
        SWatch_DW->is_alarmmode = SWatch_IN_sethours_a;

        /* Entry 'sethours': '<S3>:76' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
      } else if (*sfEvent == SWatch_event_Bswatch) {
        /* Transition: '<S3>:50' */
        SWatch_DW->is_Control = SWatch_IN_swatchmode;

        /* Entry 'swatchmode': '<S3>:38' */
        *SWatch_Y_mode = 3U;

        /* Entry Internal 'swatchmode': '<S3>:38' */
        /* Transition: '<S3>:239' */
        SWatch_DW->Ahours = 0U;
        SWatch_DW->Aminutes = 0U;
        SWatch_DW->Aseconds = 0U;
        SWatch_DW->Atenths = 0U;
        SWatch_DW->mutex = 1U;
        SWatch_DW->is_swatchmode = SWatch_IN_stop;

        /* Entry 'stop': '<S3>:207' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
        *SWatch_Y_seconds = SWatch_DW->Aseconds;
        *SWatch_Y_tenths = SWatch_DW->Atenths;
      } else {
        if (*sfEvent == SWatch_event_ptick) {
          /* Transition: '<S3>:58' */
          *SWatch_Y_hours = SWatch_DW->hours;
          *SWatch_Y_minutes = SWatch_DW->minutes;
          *SWatch_Y_seconds = SWatch_DW->seconds;
          *SWatch_Y_tenths = SWatch_DW->tenths;
        }
      }
      break;

     default:
      SWatch_timermode(sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
                       SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode,
                       SWatch_Y_Timer_exp, SWatch_DW);
      break;
    }
  }

  /* During 'TimeCount': '<S3>:14' */
  if (SWatch_DW->is_TimeCount == SWatch_IN_Timeset) {
    SWatch_Timeset(sfEvent, SWatch_Y_hours, SWatch_Y_minutes, SWatch_Y_seconds,
                   SWatch_DW);
  } else {
    /* During 'timecount': '<S3>:17' */
    if ((*sfEvent == SWatch_event_Bstop) && (SWatch_DW->mutex == 0)) {
      /* Transition: '<S3>:316' */
      SWatch_DW->is_TimeCount = SWatch_IN_Timeset;

      /* Entry Internal 'Timeset': '<S3>:315' */
      /* Transition: '<S3>:330' */
      SWatch_DW->is_Timeset = SWatch_IN_sethours_a;

      /* Entry 'sethours': '<S3>:323' */
      *SWatch_Y_hours = SWatch_DW->hours;
      SWatch_DW->seconds = 0U;
      *SWatch_Y_seconds = 0U;
      SWatch_DW->tenths = 0U;
    } else {
      if (*sfEvent == SWatch_event_ptick) {
        /* Transition: '<S3>:20' */
        tmp = (int32_T)(SWatch_DW->tenths + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        SWatch_DW->tenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 10U * 10U));
        if (SWatch_DW->tenths == 0) {
          /* Transition: '<S3>:28' */
          tmp = (int32_T)(SWatch_DW->seconds + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->seconds = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 60U * 60U));
          if (SWatch_DW->seconds == 0) {
            /* Transition: '<S3>:31' */
            tmp = (int32_T)(SWatch_DW->minutes + 1U);
            if ((uint32_T)tmp > 255U) {
              tmp = 255;
            }

            SWatch_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
              ((uint8_T)tmp / 60U * 60U));
            if (SWatch_DW->minutes == 0) {
              /* Transition: '<S3>:33' */
              tmp = (int32_T)(SWatch_DW->hours + 1U);
              if ((uint32_T)tmp > 255U) {
                tmp = 255;
              }

              SWatch_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
                ((uint8_T)tmp / 24U * 24U));

              /* Transition: '<S3>:36' */
              SWatch_DW->is_TimeCount = SWatch_IN_timecount;
            } else {
              /* Transition: '<S3>:35' */
              guard1 = true;
            }
          } else {
            /* Transition: '<S3>:29' */
            guard1 = true;
          }
        } else {
          /* Transition: '<S3>:21' */
          guard1 = true;
        }

        if (guard1) {
          /* Transition: '<S3>:37' */
          SWatch_DW->is_TimeCount = SWatch_IN_timecount;
        }
      }
    }
  }

  /* During 'AlarmMng': '<S3>:15' */
  /* During 'Alarm_signaler': '<S3>:257' */
  if ((*sfEvent == SWatch_event_ptick) && (SWatch_DW->hours ==
       SWatch_DW->Alarm_h) && (SWatch_DW->minutes == SWatch_DW->Alarm_m) &&
      (SWatch_DW->Alarm_state == 1) && (SWatch_DW->seconds == 0) &&
      (SWatch_DW->tenths == 0)) {
    /* Transition: '<S3>:259' */
    *SWatch_Y_Alarm_signal = 1U;
  }
}

/* Model step function */
void SWatch_step(RT_MODEL_SWatch_T *const SWatch_M, boolean_T SWatch_U_Bplus,
                 boolean_T SWatch_U_Bminus, boolean_T SWatch_U_Btime, boolean_T
                 SWatch_U_Btimer, boolean_T SWatch_U_Balarm, boolean_T
                 SWatch_U_Bswatch, boolean_T SWatch_U_Bstart, boolean_T
                 SWatch_U_Bstop, uint8_T *SWatch_Y_hours, uint8_T
                 *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T
                 *SWatch_Y_tenths, uint8_T *SWatch_Y_mode, uint8_T
                 *SWatch_Y_Alarm_signal, uint8_T *SWatch_Y_Timer_exp)
{
  DW_SWatch_T *SWatch_DW = ((DW_SWatch_T *) SWatch_M->ModelData.dwork);
  PrevZCX_SWatch_T *SWatch_PrevZCX = ((PrevZCX_SWatch_T *)
    SWatch_M->ModelData.prevZCSigState);
  uint8_T rtb_FixPtSum1;
  boolean_T zcEvent[9];
  int32_T sfEvent;
  boolean_T tmp;

  /* Chart: '<S1>/SWatch' incorporates:
   *  TriggerPort: '<S3>/ input events '
   */
  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  zcEvent[0] = (((SWatch_DW->Output_DSTATE != 0) !=
                 (SWatch_PrevZCX->SWatch_Trig_ZCE[0] == POS_ZCSIG)) &&
                (SWatch_PrevZCX->SWatch_Trig_ZCE[0] != UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Bplus' */
  zcEvent[1] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[1] == POS_ZCSIG) !=
                 SWatch_U_Bplus) && (SWatch_PrevZCX->SWatch_Trig_ZCE[1] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Bminus' */
  zcEvent[2] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[2] == POS_ZCSIG) !=
                 SWatch_U_Bminus) && (SWatch_PrevZCX->SWatch_Trig_ZCE[2] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Btime' */
  zcEvent[3] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[3] == POS_ZCSIG) !=
                 SWatch_U_Btime) && (SWatch_PrevZCX->SWatch_Trig_ZCE[3] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Btimer' */
  zcEvent[4] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[4] == POS_ZCSIG) !=
                 SWatch_U_Btimer) && (SWatch_PrevZCX->SWatch_Trig_ZCE[4] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Balarm' */
  zcEvent[5] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[5] == POS_ZCSIG) !=
                 SWatch_U_Balarm) && (SWatch_PrevZCX->SWatch_Trig_ZCE[5] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Bswatch' */
  zcEvent[6] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[6] == POS_ZCSIG) !=
                 SWatch_U_Bswatch) && (SWatch_PrevZCX->SWatch_Trig_ZCE[6] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Bstart' */
  zcEvent[7] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[7] == POS_ZCSIG) !=
                 SWatch_U_Bstart) && (SWatch_PrevZCX->SWatch_Trig_ZCE[7] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Bstop' */
  zcEvent[8] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[8] == POS_ZCSIG) !=
                 SWatch_U_Bstop) && (SWatch_PrevZCX->SWatch_Trig_ZCE[8] !=
    UNINITIALIZED_ZCSIG));
  tmp = false;
  for (sfEvent = 0; sfEvent < 9; sfEvent++) {
    tmp = (tmp || zcEvent[sfEvent]);
  }

  if (tmp) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  UnitDelay: '<S2>/Output'
     */
    /* Gateway: SWatch/SWatch */
    if ((int8_T)(zcEvent[0] ? SWatch_DW->Output_DSTATE != 0 ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S3>:1' */
      sfEvent = SWatch_event_ptick;
      SWatch_chartstep_c3_SWatch(&sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_Y_Alarm_signal,
        SWatch_Y_Timer_exp, SWatch_DW);
    }

    /* Inport: '<Root>/Bplus' */
    if ((int8_T)(zcEvent[1] ? SWatch_U_Bplus ? RISING_ZCEVENT : FALLING_ZCEVENT :
                 NO_ZCEVENT) == 1) {
      /* Event: '<S3>:6' */
      sfEvent = SWatch_event_Bplus;
      SWatch_chartstep_c3_SWatch(&sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_Y_Alarm_signal,
        SWatch_Y_Timer_exp, SWatch_DW);
    }

    /* Inport: '<Root>/Bminus' */
    if ((int8_T)(zcEvent[2] ? SWatch_U_Bminus ? RISING_ZCEVENT : FALLING_ZCEVENT
                 : NO_ZCEVENT) == 1) {
      /* Event: '<S3>:7' */
      sfEvent = SWatch_event_Bminus;
      SWatch_chartstep_c3_SWatch(&sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_Y_Alarm_signal,
        SWatch_Y_Timer_exp, SWatch_DW);
    }

    /* Inport: '<Root>/Btime' */
    if ((int8_T)(zcEvent[3] ? SWatch_U_Btime ? RISING_ZCEVENT : FALLING_ZCEVENT :
                 NO_ZCEVENT) == 1) {
      /* Event: '<S3>:2' */
      sfEvent = SWatch_event_Btime;
      SWatch_chartstep_c3_SWatch(&sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_Y_Alarm_signal,
        SWatch_Y_Timer_exp, SWatch_DW);
    }

    /* Inport: '<Root>/Btimer' */
    if ((int8_T)(zcEvent[4] ? SWatch_U_Btimer ? RISING_ZCEVENT : FALLING_ZCEVENT
                 : NO_ZCEVENT) == 1) {
      /* Event: '<S3>:3' */
      sfEvent = SWatch_event_Btimer;
      SWatch_chartstep_c3_SWatch(&sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_Y_Alarm_signal,
        SWatch_Y_Timer_exp, SWatch_DW);
    }

    /* Inport: '<Root>/Balarm' */
    if ((int8_T)(zcEvent[5] ? SWatch_U_Balarm ? RISING_ZCEVENT : FALLING_ZCEVENT
                 : NO_ZCEVENT) == 1) {
      /* Event: '<S3>:4' */
      sfEvent = SWatch_event_Balarm;
      SWatch_chartstep_c3_SWatch(&sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_Y_Alarm_signal,
        SWatch_Y_Timer_exp, SWatch_DW);
    }

    /* Inport: '<Root>/Bswatch' */
    if ((int8_T)(zcEvent[6] ? SWatch_U_Bswatch ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) == 1) {
      /* Event: '<S3>:189' */
      sfEvent = SWatch_event_Bswatch;
      SWatch_chartstep_c3_SWatch(&sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_Y_Alarm_signal,
        SWatch_Y_Timer_exp, SWatch_DW);
    }

    /* Inport: '<Root>/Bstart' */
    if ((int8_T)(zcEvent[7] ? SWatch_U_Bstart ? RISING_ZCEVENT : FALLING_ZCEVENT
                 : NO_ZCEVENT) == 1) {
      /* Event: '<S3>:190' */
      sfEvent = SWatch_event_Bstart;
      SWatch_chartstep_c3_SWatch(&sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_Y_Alarm_signal,
        SWatch_Y_Timer_exp, SWatch_DW);
    }

    /* Inport: '<Root>/Bstop' */
    if ((int8_T)(zcEvent[8] ? SWatch_U_Bstop ? RISING_ZCEVENT : FALLING_ZCEVENT :
                 NO_ZCEVENT) == 1) {
      /* Event: '<S3>:191' */
      sfEvent = SWatch_event_Bstop;
      SWatch_chartstep_c3_SWatch(&sfEvent, SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_Y_Alarm_signal,
        SWatch_Y_Timer_exp, SWatch_DW);
    }
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  SWatch_PrevZCX->SWatch_Trig_ZCE[0] = (uint8_T)(SWatch_DW->Output_DSTATE != 0);

  /* Inport: '<Root>/Bplus' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[1] = SWatch_U_Bplus;

  /* Inport: '<Root>/Bminus' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[2] = SWatch_U_Bminus;

  /* Inport: '<Root>/Btime' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[3] = SWatch_U_Btime;

  /* Inport: '<Root>/Btimer' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[4] = SWatch_U_Btimer;

  /* Inport: '<Root>/Balarm' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[5] = SWatch_U_Balarm;

  /* Inport: '<Root>/Bswatch' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[6] = SWatch_U_Bswatch;

  /* Inport: '<Root>/Bstart' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[7] = SWatch_U_Bstart;

  /* Inport: '<Root>/Bstop' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[8] = SWatch_U_Bstop;

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)(SWatch_DW->Output_DSTATE + 1U);

  /* Switch: '<S5>/FixPt Switch' */
  if (rtb_FixPtSum1 > 1) {
    /* Update for UnitDelay: '<S2>/Output' incorporates:
     *  Constant: '<S5>/Constant'
     */
    SWatch_DW->Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S2>/Output' */
    SWatch_DW->Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S5>/FixPt Switch' */
}

/* Model initialize function */
void SWatch_initialize(RT_MODEL_SWatch_T *const SWatch_M, boolean_T
  *SWatch_U_Bplus, boolean_T *SWatch_U_Bminus, boolean_T *SWatch_U_Btime,
  boolean_T *SWatch_U_Btimer, boolean_T *SWatch_U_Balarm, boolean_T
  *SWatch_U_Bswatch, boolean_T *SWatch_U_Bstart, boolean_T *SWatch_U_Bstop,
  uint8_T *SWatch_Y_hours, uint8_T *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds,
  uint8_T *SWatch_Y_tenths, uint8_T *SWatch_Y_mode, uint8_T
  *SWatch_Y_Alarm_signal, uint8_T *SWatch_Y_Timer_exp)
{
  DW_SWatch_T *SWatch_DW = ((DW_SWatch_T *) SWatch_M->ModelData.dwork);
  PrevZCX_SWatch_T *SWatch_PrevZCX = ((PrevZCX_SWatch_T *)
    SWatch_M->ModelData.prevZCSigState);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)SWatch_DW, 0,
                sizeof(DW_SWatch_T));

  /* external inputs */
  (*SWatch_U_Bplus) = false;
  (*SWatch_U_Bminus) = false;
  (*SWatch_U_Btime) = false;
  (*SWatch_U_Btimer) = false;
  (*SWatch_U_Balarm) = false;
  (*SWatch_U_Bswatch) = false;
  (*SWatch_U_Bstart) = false;
  (*SWatch_U_Bstop) = false;

  /* external outputs */
  (*SWatch_Y_hours) = 0U;
  (*SWatch_Y_minutes) = 0U;
  (*SWatch_Y_seconds) = 0U;
  (*SWatch_Y_tenths) = 0U;
  (*SWatch_Y_mode) = 0U;
  (*SWatch_Y_Alarm_signal) = 0U;
  (*SWatch_Y_Timer_exp) = 0U;

  {
    int32_T i;
    for (i = 0; i < 9; i++) {
      SWatch_PrevZCX->SWatch_Trig_ZCE[i] = UNINITIALIZED_ZCSIG;
    }

    /* InitializeConditions for Chart: '<S1>/SWatch' */
    SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_swatchmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_timermode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Timer = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Timeset = SWatch_IN_NO_ACTIVE_CHILD;

    /* Entry: SWatch/SWatch */
    /* Entry Internal: SWatch/SWatch */
    /* Entry Internal 'Control': '<S3>:13' */
    /* Transition: '<S3>:24' */
    SWatch_DW->Ahours = 0U;
    SWatch_DW->Aminutes = 0U;
    SWatch_DW->is_Control = SWatch_IN_timemode;

    /* InitializeConditions for Outport: '<Root>/mode' incorporates:
     *  InitializeConditions for Chart: '<S1>/SWatch'
     */
    /* Entry 'timemode': '<S3>:22' */
    *SWatch_Y_mode = 0U;

    /* InitializeConditions for Chart: '<S1>/SWatch' */
    /* Entry Internal 'TimeCount': '<S3>:14' */
    /* Transition: '<S3>:18' */
    SWatch_DW->hours = 0U;
    SWatch_DW->minutes = 0U;
    SWatch_DW->seconds = 0U;
    SWatch_DW->tenths = 0U;
    SWatch_DW->mutex = 0U;
    SWatch_DW->is_TimeCount = SWatch_IN_timecount;

    /* InitializeConditions for Outport: '<Root>/Alarm_signal' incorporates:
     *  InitializeConditions for Chart: '<S1>/SWatch'
     */
    /* Entry Internal 'AlarmMng': '<S3>:15' */
    /* Transition: '<S3>:258' */
    *SWatch_Y_Alarm_signal = 0U;

    /* InitializeConditions for Chart: '<S1>/SWatch' */
    SWatch_DW->Alarm_h = 0U;
    SWatch_DW->Alarm_m = 0U;
    SWatch_DW->Alarm_state = 0U;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
