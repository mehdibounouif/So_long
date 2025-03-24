define display_list
    set $node = $arg0
        printf "----------------------------------\n"
    while ($node != 0)
        p *($node)
        set $node = $node->next
    end
end

define display_address
        set $node = $arg0
        printf "----------------------------------\n"
        while ($node != 0)
                p $node
                set $node = $node->next
        end
end

