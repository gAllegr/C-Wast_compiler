(module
  (import "console" "log" (func $log (param i32) (param i32)))
  (import "js" "mem" (memory 1))
  (data (i32.const 0) "NOT case")
  (data (i32.const 50) "AND case")
  (data (i32.const 100) "OR case")
  (func (export "main") (result i32)
    (local $cond i32)
    (set_local $cond (i32.const 5))

    (if (i32.eq (i32.eqz (get_local $cond)) (i32.const 5))
        (then   
            (call $log
                (i32.const 0)
                (i32.const 8)
            )
        )
    )

    ( if (i32.and (i32.lt_s (get_local $cond) (i32.const 7)) (i32.gt_s (get_local $cond) (i32.const 3)))   
        (then   
            (call $log
                (i32.const 50)
                (i32.const 8)
            )
        )
    )

    ( if (i32.or (i32.gt_s (get_local $cond) (i32.const 2)) (i32.lt_s (get_local $cond) (i32.const 1)))   
        (then   
            (call $log
                (i32.const 100)
                (i32.const 7)
            )
        )
    )

    (return (i32.const 0))
  )
)