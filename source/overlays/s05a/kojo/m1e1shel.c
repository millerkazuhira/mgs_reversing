#include "game/game.h"

typedef struct _Work
{
    GV_ACT  actor;                                    /* 0x000 */
    CONTROL control;                                  /* 0x020 */
    OBJECT  body;                                     /* 0x09C */
    char    pad_17c[0x24C - 0x9C - sizeof(OBJECT)];   /* 0x17C */
} Work;

typedef struct
{
    GV_ACT   actor;                 /* 0x00 */
    int      field_20;              /* 0x20 */
    DG_PRIM *prim;                  /* 0x24 */
    char     pad_28[0x68 - 0x28];   /* 0x28 */
    int      field_68;              /* 0x68 */
    int      field_6c;              /* 0x6C */
    int      field_70;              /* 0x70 */
    int      field_74;              /* 0x74 */
} ShellWork;

typedef struct
{
    GV_ACT   actor;      /* 0x00 */
    int      field_20;   /* 0x20 */
    SVECTOR  field_24;   /* 0x24 */
    SVECTOR  field_2c;   /* 0x2C */
    int      field_34;   /* 0x34 */
} SmokeWork;

void s05a_800DBF58(int a0, SVECTOR *a1, SVECTOR *a2);

#pragma INCLUDE_ASM("asm/overlays/s05a/s05a_800DAE58.s")
#pragma INCLUDE_ASM("asm/overlays/s05a/s05a_800DB278.s")

void s05a_800DB654(Work *work)
{
    GM_FreeControl(&work->control);
    GM_FreeObject(&work->body);
}

#pragma INCLUDE_ASM("asm/overlays/s05a/s05a_800DB684.s")
void s05a_800DBA94(ShellWork *work)
{
    GM_CurrentMap = work->field_20;

    work->field_68 += 1;
    work->field_6c -= 25;
    if (work->field_6c < 0)
    {
        work->field_6c = 0;
    }
    work->field_70 -= 22;
    if (work->field_70 < 0)
    {
        work->field_70 = 0;
    }
    work->field_74 -= 19;
    if (work->field_74 < 0)
    {
        work->field_74 = 0;
    }

    ((POLY_FT4 *)work->prim->packs[0])[0].r0 = work->field_6c;
    ((POLY_FT4 *)work->prim->packs[0])[0].g0 = work->field_70;
    ((POLY_FT4 *)work->prim->packs[0])[0].b0 = work->field_74;
    ((POLY_FT4 *)work->prim->packs[0])[1].r0 = work->field_6c;
    ((POLY_FT4 *)work->prim->packs[0])[1].g0 = work->field_70;
    ((POLY_FT4 *)work->prim->packs[0])[1].b0 = work->field_74;
    ((POLY_FT4 *)work->prim->packs[1])[0].r0 = work->field_6c;
    ((POLY_FT4 *)work->prim->packs[1])[0].g0 = work->field_70;
    ((POLY_FT4 *)work->prim->packs[1])[0].b0 = work->field_74;
    ((POLY_FT4 *)work->prim->packs[1])[1].r0 = work->field_6c;
    ((POLY_FT4 *)work->prim->packs[1])[1].g0 = work->field_70;
    ((POLY_FT4 *)work->prim->packs[1])[1].b0 = work->field_74;

    if (work->field_68 >= 11)
    {
        GV_DestroyActor(&work->actor);
    }
}

void s05a_800DBC44(ShellWork *work)
{
    GM_FreePrim(work->prim);
}

#pragma INCLUDE_ASM("asm/overlays/s05a/s05a_800DBC80.s")
#pragma INCLUDE_ASM("asm/overlays/s05a/s05a_800DBD14.s")

void s05a_800DBED0(SmokeWork *work)
{
    int state;

    GM_CurrentMap = work->field_20;
    state = work->field_34 + 1;
    work->field_34 = state;
    if (state == 1)
    {
        s05a_800DBF58(1, &work->field_24, &work->field_2c);
    }
    else if (state == 2)
    {
        sub_8007913C();
    }
    else if (state >= 30)
    {
        GV_DestroyActor(&work->actor);
    }
}

void s05a_800DBF50(void *work)
{
    /* do nothing */
}
