Module find_prime_main

    Dim bol_primesRaster() As Boolean
    'Dim lst_foundprimes As List(Of Int32)
    Dim dt_start As Date
    Dim dt_ende As Date

    Public Sub Main(sArgs() As String)
        '
        dt_start = Now

        'Plausi: Wurden Paramater angege
        If sArgs.Length = 0 Then
            Console.WriteLine("Kein Parameter!")
            End
        End If

        If sArgs.Length > 2 Then
            Console.WriteLine("Zu viele Parameter!")
            End
        End If

        If Not IsNumeric(sArgs(0)) Then
            Console.WriteLine("Die Obergrenze muss eine Zahl sein!")
            End
        End If

        Dim int_iterations As Int32

        If sArgs.Length = 2 Then
            If IsNumeric(sArgs(1)) Then
                int_iterations = CInt(sArgs(1))
            Else
                int_iterations = 1
            End If
        End If

        Dim rp As Int32
        Dim primescount As Int32
        Dim int_Obergrenze As Int32

        Dim y As Int32
        Dim int_GrQuadrat As Int32
        Dim i As Int32

        int_Obergrenze = CInt(sArgs(0))
        int_GrQuadrat = Math.Round(Math.Sqrt(int_Obergrenze))
        int_Obergrenze = (int_Obergrenze / 2) - 1


        For rp = 0 To int_iterations
            primescount = 0
            ReDim bol_primesRaster(0 To int_Obergrenze)

            For i = 3 To int_GrQuadrat Step 2
                Calculation(i, int_Obergrenze)
            Next

            For y = 1 To bol_primesRaster.Length - 1
                If bol_primesRaster(y) = False Then
                    primescount = primescount + 1
                End If
            Next

        Next rp

        dt_ende = Now
        Dim interval As TimeSpan = dt_ende - dt_start


        Console.WriteLine("Operationsdauer: " & interval.TotalMilliseconds & " ms")
        Console.WriteLine("Gefundene Primzahlen: " & primescount + 1)


        'Test für die richtige Berechnung
        'For y = 1 To 200
        '    If bol_primesRaster(y) = False Then
        '        Console.WriteLine("Die Zahl " & (y * 2) + 1 & " ist eine Primzahl: " & Not bol_primesRaster(y))
        '    End If
        'Next

        'Ausgabe der Gefundenen Primzahlen
        'Dim strPrimzahlen As String
        'strPrimzahlen = "2"
        'For y = 1 To bol_primesRaster.Length - 1
        '    If bol_primesRaster(y) = False Then
        '        strPrimzahlen = strPrimzahlen & ", " & CStr((y * 2) + 1)
        '    End If
        'Next
        'Console.WriteLine(strPrimzahlen)

    End Sub

    Sub Calculation(ByVal int_zahl As Int32, ByVal int_Obergrenze As Int32)
        Dim i As Int32
        Dim strt As Int32

        strt = ((int_zahl * int_zahl) - 1) / 2

        For i = strt To int_Obergrenze Step int_zahl
            bol_primesRaster(i) = True
        Next

    End Sub

End Module
