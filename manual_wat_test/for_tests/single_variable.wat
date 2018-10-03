(module
  (import "console" "log" (func $log (param i32)))
  (func (export "main") (result i32)
    (local $N i32)
    (local $i i32)
    (local $s i32)

    (set_local $N (i32.const 10))
    (set_local $s (i32.const 0))

    (set_local $i (i32.const 0))
    (loop $loop
        (set_local $s
            (i32.add
                (get_local $s)
                (get_local $i)
            )
        )

        (call $log (get_local $i))
        (call $log (get_local $s))
        
        (br_if $loop
            (i32.le_s
                (tee_local $i
                    (i32.add
                        (get_local $i)
                        (i32.const 1)
                    )
                )
                (get_local $N)
            )
        )
    )

    (return (i32.const 0))
  )
)