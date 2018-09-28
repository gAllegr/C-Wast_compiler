(module
  (import "console" "log" (func $log (param i32) (param i32)))
  (import "js" "mem" (memory 1))
  (data (i32.const 0) "Variable has a value greater then 5")
  (data (i32.const 50) "b")
  (func (export "main") 
    (local $cond i32)
    (local $b i32)

    (set_local $cond (i32.const 5))   

    (if (i32.gt_s (get_local $cond) (i32.const 5)) 
        (then 
            (call $log
                (i32.const 0)
                (i32.const 35)
            )
        )
        (else
            (set_local $b (i32.const 50))   
            (call $log
                (get_local $b)
                (i32.const 1)
            )
        )
    )

    (return (i32.const 0))
  )
)