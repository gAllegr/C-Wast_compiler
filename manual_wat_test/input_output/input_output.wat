(module
    (import "console" "str_log" (func $str_log (param i32) (param i32)))
    (import "console" "log" (func $log (param i32)))
;;    (import "console" "scanf" (func $scanf))
    (import "js" "mem" (memory 1))
    (data (i32.const 0) "Insert the value of the a variable: ")
    (data (i32.const 36) "Insert the value of 'b' and 'c' variables: ")
    (global $v (import "js" "value") (mut i32))
    (global $a (mut i32) (i32.const 0))
    (global $b (mut i32) (i32.const 0))
    (global $c (mut i32) (i32.const 0))
    (func (export "main")
        (call $str_log
            (i32.const 0)
            (i32.const 36)
        )

        (call $str_log
            (i32.const 0)
            (i32.const 37)
        )

        (call $str_log
            (i32.const 36)
            (i32.const 44)
        )

        ;;(call $scanf)

;;        (call $log
  ;;          (get_global $v)
    ;;    )
    )



)