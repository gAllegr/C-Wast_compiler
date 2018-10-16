(module

  (import "console" "str_log" (func $str_log (param i32) (param i32)))
  (import "js" "mem" (memory 1))

  (data (i32.const 0) "Something")

  (func (export "main") (result i32)

    (local $a i32)
    (local $b i32)
    (set_local $a (i32.const 2))
    (set_local $b (i32.const 4))
    (if (i32.and (i32.gt_s (get_local $a) (i32.const 0)) (i32.gt_s (get_local $b) (get_local $a)))
      (then
        (call $str_log
          (i32.const 0)
          (i32.const 9)
        )
      )
    )
    (return (i32.const 0))
  )
)