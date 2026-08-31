select sample_id, dna_sequence, species, 
CASE when dna_sequence LIKE 'ATG%' then 1 else 0 
    end as has_start,
CASE when dna_sequence LIKE '%TAA' 
    or dna_sequence LIKE '%TAG' 
    or dna_sequence LIKE '%TGA'
    then 1 else 0 
    end as has_stop,
CASE when dna_sequence LIKE '%ATAT%' then 1 else 0 
    end as has_atat,
CASE when dna_sequence LIKE '%GGG%' then 1 else 0 
    end as has_ggg
from Samples
-- (WHERE dna_sequence LIKE 'ATG%') as has_start,
-- (WHERE dna_sequence LIKE '%TAA','%TAG','%TGA') as has_end, 
-- (WHERE dna_sequence LIKE '%ATAT%') as has_atat, 
-- (WHERE dna_sequence LIKE '%GGG%') as has_ggg
-- from Samples