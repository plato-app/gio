// SPDX-License-Identifier: Apache-2.0 OR MIT OR Unlicense

// Code auto-generated by piet-gpu-derive

struct CmdStrokeRef {
    uint offset;
};

struct CmdFillRef {
    uint offset;
};

struct CmdFillImageRef {
    uint offset;
};

struct CmdBeginClipRef {
    uint offset;
};

struct CmdBeginSolidClipRef {
    uint offset;
};

struct CmdEndClipRef {
    uint offset;
};

struct CmdSolidRef {
    uint offset;
};

struct CmdSolidImageRef {
    uint offset;
};

struct CmdJumpRef {
    uint offset;
};

struct CmdRef {
    uint offset;
};

struct CmdStroke {
    uint tile_ref;
    float half_width;
    uint rgba_color;
};

#define CmdStroke_size 12

CmdStrokeRef CmdStroke_index(CmdStrokeRef ref, uint index) {
    return CmdStrokeRef(ref.offset + index * CmdStroke_size);
}

struct CmdFill {
    uint tile_ref;
    int backdrop;
    uint rgba_color;
};

#define CmdFill_size 12

CmdFillRef CmdFill_index(CmdFillRef ref, uint index) {
    return CmdFillRef(ref.offset + index * CmdFill_size);
}

struct CmdFillImage {
    uint tile_ref;
    int backdrop;
    uint index;
    ivec2 offset;
};

#define CmdFillImage_size 16

CmdFillImageRef CmdFillImage_index(CmdFillImageRef ref, uint index) {
    return CmdFillImageRef(ref.offset + index * CmdFillImage_size);
}

struct CmdBeginClip {
    uint tile_ref;
    int backdrop;
};

#define CmdBeginClip_size 8

CmdBeginClipRef CmdBeginClip_index(CmdBeginClipRef ref, uint index) {
    return CmdBeginClipRef(ref.offset + index * CmdBeginClip_size);
}

struct CmdBeginSolidClip {
    float alpha;
};

#define CmdBeginSolidClip_size 4

CmdBeginSolidClipRef CmdBeginSolidClip_index(CmdBeginSolidClipRef ref, uint index) {
    return CmdBeginSolidClipRef(ref.offset + index * CmdBeginSolidClip_size);
}

struct CmdEndClip {
    float alpha;
};

#define CmdEndClip_size 4

CmdEndClipRef CmdEndClip_index(CmdEndClipRef ref, uint index) {
    return CmdEndClipRef(ref.offset + index * CmdEndClip_size);
}

struct CmdSolid {
    uint rgba_color;
};

#define CmdSolid_size 4

CmdSolidRef CmdSolid_index(CmdSolidRef ref, uint index) {
    return CmdSolidRef(ref.offset + index * CmdSolid_size);
}

struct CmdSolidImage {
    uint index;
    ivec2 offset;
};

#define CmdSolidImage_size 8

CmdSolidImageRef CmdSolidImage_index(CmdSolidImageRef ref, uint index) {
    return CmdSolidImageRef(ref.offset + index * CmdSolidImage_size);
}

struct CmdJump {
    uint new_ref;
};

#define CmdJump_size 4

CmdJumpRef CmdJump_index(CmdJumpRef ref, uint index) {
    return CmdJumpRef(ref.offset + index * CmdJump_size);
}

#define Cmd_End 0
#define Cmd_Fill 1
#define Cmd_FillImage 2
#define Cmd_BeginClip 3
#define Cmd_BeginSolidClip 4
#define Cmd_EndClip 5
#define Cmd_Stroke 6
#define Cmd_Solid 7
#define Cmd_SolidImage 8
#define Cmd_Jump 9
#define Cmd_size 20

CmdRef Cmd_index(CmdRef ref, uint index) {
    return CmdRef(ref.offset + index * Cmd_size);
}

CmdStroke CmdStroke_read(Alloc a, CmdStrokeRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    uint raw1 = read_mem(a, ix + 1);
    uint raw2 = read_mem(a, ix + 2);
    CmdStroke s;
    s.tile_ref = raw0;
    s.half_width = uintBitsToFloat(raw1);
    s.rgba_color = raw2;
    return s;
}

void CmdStroke_write(Alloc a, CmdStrokeRef ref, CmdStroke s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.tile_ref);
    write_mem(a, ix + 1, floatBitsToUint(s.half_width));
    write_mem(a, ix + 2, s.rgba_color);
}

CmdFill CmdFill_read(Alloc a, CmdFillRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    uint raw1 = read_mem(a, ix + 1);
    uint raw2 = read_mem(a, ix + 2);
    CmdFill s;
    s.tile_ref = raw0;
    s.backdrop = int(raw1);
    s.rgba_color = raw2;
    return s;
}

void CmdFill_write(Alloc a, CmdFillRef ref, CmdFill s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.tile_ref);
    write_mem(a, ix + 1, uint(s.backdrop));
    write_mem(a, ix + 2, s.rgba_color);
}

CmdFillImage CmdFillImage_read(Alloc a, CmdFillImageRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    uint raw1 = read_mem(a, ix + 1);
    uint raw2 = read_mem(a, ix + 2);
    uint raw3 = read_mem(a, ix + 3);
    CmdFillImage s;
    s.tile_ref = raw0;
    s.backdrop = int(raw1);
    s.index = raw2;
    s.offset = ivec2(int(raw3 << 16) >> 16, int(raw3) >> 16);
    return s;
}

void CmdFillImage_write(Alloc a, CmdFillImageRef ref, CmdFillImage s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.tile_ref);
    write_mem(a, ix + 1, uint(s.backdrop));
    write_mem(a, ix + 2, s.index);
    write_mem(a, ix + 3, (uint(s.offset.x) & 0xffff) | (uint(s.offset.y) << 16));
}

CmdBeginClip CmdBeginClip_read(Alloc a, CmdBeginClipRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    uint raw1 = read_mem(a, ix + 1);
    CmdBeginClip s;
    s.tile_ref = raw0;
    s.backdrop = int(raw1);
    return s;
}

void CmdBeginClip_write(Alloc a, CmdBeginClipRef ref, CmdBeginClip s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.tile_ref);
    write_mem(a, ix + 1, uint(s.backdrop));
}

CmdBeginSolidClip CmdBeginSolidClip_read(Alloc a, CmdBeginSolidClipRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    CmdBeginSolidClip s;
    s.alpha = uintBitsToFloat(raw0);
    return s;
}

void CmdBeginSolidClip_write(Alloc a, CmdBeginSolidClipRef ref, CmdBeginSolidClip s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, floatBitsToUint(s.alpha));
}

CmdEndClip CmdEndClip_read(Alloc a, CmdEndClipRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    CmdEndClip s;
    s.alpha = uintBitsToFloat(raw0);
    return s;
}

void CmdEndClip_write(Alloc a, CmdEndClipRef ref, CmdEndClip s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, floatBitsToUint(s.alpha));
}

CmdSolid CmdSolid_read(Alloc a, CmdSolidRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    CmdSolid s;
    s.rgba_color = raw0;
    return s;
}

void CmdSolid_write(Alloc a, CmdSolidRef ref, CmdSolid s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.rgba_color);
}

CmdSolidImage CmdSolidImage_read(Alloc a, CmdSolidImageRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    uint raw1 = read_mem(a, ix + 1);
    CmdSolidImage s;
    s.index = raw0;
    s.offset = ivec2(int(raw1 << 16) >> 16, int(raw1) >> 16);
    return s;
}

void CmdSolidImage_write(Alloc a, CmdSolidImageRef ref, CmdSolidImage s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.index);
    write_mem(a, ix + 1, (uint(s.offset.x) & 0xffff) | (uint(s.offset.y) << 16));
}

CmdJump CmdJump_read(Alloc a, CmdJumpRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = read_mem(a, ix + 0);
    CmdJump s;
    s.new_ref = raw0;
    return s;
}

void CmdJump_write(Alloc a, CmdJumpRef ref, CmdJump s) {
    uint ix = ref.offset >> 2;
    write_mem(a, ix + 0, s.new_ref);
}

uint Cmd_tag(Alloc a, CmdRef ref) {
    return read_mem(a, ref.offset >> 2);
}

CmdFill Cmd_Fill_read(Alloc a, CmdRef ref) {
    return CmdFill_read(a, CmdFillRef(ref.offset + 4));
}

CmdFillImage Cmd_FillImage_read(Alloc a, CmdRef ref) {
    return CmdFillImage_read(a, CmdFillImageRef(ref.offset + 4));
}

CmdBeginClip Cmd_BeginClip_read(Alloc a, CmdRef ref) {
    return CmdBeginClip_read(a, CmdBeginClipRef(ref.offset + 4));
}

CmdBeginSolidClip Cmd_BeginSolidClip_read(Alloc a, CmdRef ref) {
    return CmdBeginSolidClip_read(a, CmdBeginSolidClipRef(ref.offset + 4));
}

CmdEndClip Cmd_EndClip_read(Alloc a, CmdRef ref) {
    return CmdEndClip_read(a, CmdEndClipRef(ref.offset + 4));
}

CmdStroke Cmd_Stroke_read(Alloc a, CmdRef ref) {
    return CmdStroke_read(a, CmdStrokeRef(ref.offset + 4));
}

CmdSolid Cmd_Solid_read(Alloc a, CmdRef ref) {
    return CmdSolid_read(a, CmdSolidRef(ref.offset + 4));
}

CmdSolidImage Cmd_SolidImage_read(Alloc a, CmdRef ref) {
    return CmdSolidImage_read(a, CmdSolidImageRef(ref.offset + 4));
}

CmdJump Cmd_Jump_read(Alloc a, CmdRef ref) {
    return CmdJump_read(a, CmdJumpRef(ref.offset + 4));
}

void Cmd_End_write(Alloc a, CmdRef ref) {
    write_mem(a, ref.offset >> 2, Cmd_End);
}

void Cmd_Fill_write(Alloc a, CmdRef ref, CmdFill s) {
    write_mem(a, ref.offset >> 2, Cmd_Fill);
    CmdFill_write(a, CmdFillRef(ref.offset + 4), s);
}

void Cmd_FillImage_write(Alloc a, CmdRef ref, CmdFillImage s) {
    write_mem(a, ref.offset >> 2, Cmd_FillImage);
    CmdFillImage_write(a, CmdFillImageRef(ref.offset + 4), s);
}

void Cmd_BeginClip_write(Alloc a, CmdRef ref, CmdBeginClip s) {
    write_mem(a, ref.offset >> 2, Cmd_BeginClip);
    CmdBeginClip_write(a, CmdBeginClipRef(ref.offset + 4), s);
}

void Cmd_BeginSolidClip_write(Alloc a, CmdRef ref, CmdBeginSolidClip s) {
    write_mem(a, ref.offset >> 2, Cmd_BeginSolidClip);
    CmdBeginSolidClip_write(a, CmdBeginSolidClipRef(ref.offset + 4), s);
}

void Cmd_EndClip_write(Alloc a, CmdRef ref, CmdEndClip s) {
    write_mem(a, ref.offset >> 2, Cmd_EndClip);
    CmdEndClip_write(a, CmdEndClipRef(ref.offset + 4), s);
}

void Cmd_Stroke_write(Alloc a, CmdRef ref, CmdStroke s) {
    write_mem(a, ref.offset >> 2, Cmd_Stroke);
    CmdStroke_write(a, CmdStrokeRef(ref.offset + 4), s);
}

void Cmd_Solid_write(Alloc a, CmdRef ref, CmdSolid s) {
    write_mem(a, ref.offset >> 2, Cmd_Solid);
    CmdSolid_write(a, CmdSolidRef(ref.offset + 4), s);
}

void Cmd_SolidImage_write(Alloc a, CmdRef ref, CmdSolidImage s) {
    write_mem(a, ref.offset >> 2, Cmd_SolidImage);
    CmdSolidImage_write(a, CmdSolidImageRef(ref.offset + 4), s);
}

void Cmd_Jump_write(Alloc a, CmdRef ref, CmdJump s) {
    write_mem(a, ref.offset >> 2, Cmd_Jump);
    CmdJump_write(a, CmdJumpRef(ref.offset + 4), s);
}

