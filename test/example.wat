(module
 (type $FUNCSIG$ii (func (param i32) (result i32)))
 (type $FUNCSIG$iii (func (param i32 i32) (result i32)))
 (import "env" "printf" (func $printf (param i32 i32) (result i32)))
 (import "env" "scanf" (func $scanf (param i32 i32) (result i32)))
 (table 0 anyfunc)
 (memory $0 1)
 (data (i32.const 16) "How many numbers you want to sum?\n\00")
 (data (i32.const 64) "%d\00")
 (export "memory" (memory $0))
 (export "main" (func $main))
 (func $main (; 2 ;) (result i32)
  (local $0 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $0
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (i32.store offset=12
   (get_local $0)
   (i32.const 0)
  )
  (drop
   (call $printf
    (i32.const 16)
    (i32.const 0)
   )
  )
  (i32.store
   (get_local $0)
   (i32.add
    (get_local $0)
    (i32.const 8)
   )
  )
  (drop
   (call $scanf
    (i32.const 64)
    (get_local $0)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $0)
    (i32.const 16)
   )
  )
  (i32.const 0)
 )
)
